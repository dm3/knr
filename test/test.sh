#!/bin/sh

root="$HOME/projects/c/knr"
tests="$root/test"
src="$root/src"
target="$root/target"

# -- preconditions
# exercise number
if [[ -z $1 ]]; then
    echo "First argument should be the number of the exercise (like 1.1 or 2.12)."
    exit 1
fi

# target directory
if [[ -d "$target" ]]; then
    rm -rf "$target"
fi
mkdir $target
if [[ 0 -eq "$?" ]]; then
    echo "Created $target directory for compiled files."
else
    echo "Failed to create $target dir for compiled files."
fi

# -- arguments
# transform 1.22 to 122
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
# compile shared libraries (inefficient, should be using make)
libs=`find "$src/lib" -name '*.c'`
# compile the exercise
file=`find "$src" -name "*_$exercise.c"`
echo "Found $file source file."

exec="$target/$exercise.out"
gcc -W -Wall -ansi -pedantic -std=c99 -lm -g "$libs" "$file" -o "$exec"

if [[ 0 -eq "$?" ]]; then
    echo "Compiled $file to $exec"
    chmod u+x "$exec"
else
    echo "Failed to compile $file"
    exit 1
fi

# -- actual testing
# run the program
exec_cmd="$exec"
exercise_tests="$tests/ex_$exercise"
if [[ ! -d "$exercise_tests" ]]; then
    echo "No tests found for exercise '$exercise'. Running bare."
    echo ""
    $exec_cmd
    exit 0;
fi
for input in `find "$exercise_tests" -name "in_$test_nums"`; do
    number="${input##*in_}"
    output_file="$target/$number"
    "$exec_cmd" < "$input" > "$output_file"

    expected_output="$tests/ex_$exercise/out_$number"
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
