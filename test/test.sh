#!/bin/sh

ALL_FLAG='ALL'

ROOT="$HOME/projects/c/knr"
src="$ROOT/src"
TESTS="$ROOT/test"
TARGET="$ROOT/target"
LIB="$src/lib"

function compile_libs() {
    for lib in `find "$LIB" -name '*.c'`; do
        libname=`basename $lib`
        gcc -W -Wall -ansi -pedantic -std=c99 -lm -g -c "$lib" -o "$TARGET/lib-${libname%.*}.o"
        if [[ 0 -ne $? ]]; then
            echo "Failed to compile lib: $lib"
        fi
    done
}

function compile() {
    libs=$1
    source=$2
    executable=$3

    gcc -W -Wall -ansi -pedantic -std=c99 -lm -g $libs "$source" -o "$executable"
}

function compile_exercise() {
    exercise=$1
    executable=$2

    file=`find "$src" -name "*_$exercise.c"`
    echo "Found $file source file."

    libs=`find $TARGET -name "lib-*.o"`
    compile "$libs" "$file" "$executable"

    if [[ 0 -eq "$?" ]]; then
        echo "Compiled $file to $executable"
        chmod u+x "$executable"
        return 0
    else
        echo "Failed to compile $file"
        return 1
    fi
}

# @param 1 - name (id) of the exercise
# @returns 0 if the exercise has tests, 1 otherwise
function has_tests() {
    exercise=$1

    exercise_tests="$TESTS/ex_$exercise"
    if [[ -d "$exercise_tests" ]]; then
        return 0;
    fi
    return 1;
}

function run_tests() {
    exercise=$1
    exec_cmd=$2
    test_nums=$3

    exercise_tests="$TESTS/ex_$exercise"
    for input in `find "$exercise_tests" -name "in_$test_nums"`; do
        number="${input##*in_}"
        output_file="$TARGET/$number"
        "$exec_cmd" < "$input" > "$output_file"

        expected_output="$TESTS/ex_$exercise/out_$number"
        if [[ ! -f "$expected_output" ]]; then
            echo "There is no expected output file for $input input file!"
        else
            diff "$output_file" "$expected_output" > /dev/null
            if [[ 0 -eq "$?" ]]; then
                echo "OK: $number"
            else
                echo "FAILURE: $number"
                echo "--- DIFF ---"
                diff "$output_file" "$expected_output"
                echo "--- END DIFF ---"
            fi
        fi
    done
}

# -- preconditions
# exercise number
if [[ -z $1 ]]; then
    echo "First argument should be the number of the exercise (like 1.1 or 2.12)"
    echo "or $ALL_FLAG switch, which will compile all of the programs and run all of the existing tests."
    exit 1
fi

# target directory
if [[ -d "$TARGET" ]]; then
    rm -rf "$TARGET"
fi
mkdir $TARGET
if [[ 0 -eq "$?" ]]; then
    echo "Created $TARGET directory for compiled files."
else
    echo "Failed to create $TARGET dir for compiled files."
fi

# -- arguments
# transform 1.22 to 122
if [[ $1 == $ALL_FLAG ]]; then
    files=`find "$src" -name '*.c'`
    for file in $files; do
        echo "$file"
    done
fi

exercise=${1/./}
shift

if [[ $# -gt 0 ]]; then
    # construct a character regex
    test_nums='['
    while (("$#")); do
        test_nums="$test_nums$1"
        shift
    done
    test_nums="$test_nums]"
else
    test_nums='*'
fi

# -- action
compile_libs
exec="$TARGET/$exercise.out"
compile_exercise "$exercise" "$exec"

if [[ 0 -ne $? ]]; then
    exit 1
fi

# -- actual testing
has_tests "$exercise"
if [[ 0 -eq $? ]]; then
    echo "Running tests..."
    run_tests "$exercise" "$exec" "$test_nums"
else
    echo "No tests found for exercise '$exercise'. Running bare."
    echo ""
    $exec
fi
