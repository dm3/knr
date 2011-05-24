#!/bin/sh

root="$HOME/projects/c/knr"
tests="$root/test"
src="$root/chapter1"
target="$root/target"

# preconditions:
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

# exercise number
if [[ -z $1 ]]; then
    echo "First argument should be the number of the exercise (like 1.1 or 2.12)."
    exit 1
fi
# transform 1.22 to 122
exercise=${1/./}

# action:
# compile the exercise
file=`find "$src" -name "*$exercise.c"`
echo "Found $file source file."

exec="$target/$exercise.out"
gcc -std=c99 "$file" -o "$exec"

if [[ 0 -eq "$?" ]]; then
    echo "Compiled $file to $exec"
    chmod u+x "$exec"
else
    echo "Failed to compile $file"
    exit 1
fi

# actual testing:
# run the program
exercise_tests="$tests/ex_$exercise"
for input in `find "$exercise_tests" -name 'in_*'`; do
    number="${input##*in_}"
    output_file="$target/$number"
    "$exec" < "$input" > "$output_file"

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
