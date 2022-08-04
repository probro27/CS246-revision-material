#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Incorrect number of arguments" >&2
    exit 1
fi

if [ $1 -lt 1 ]; then
    echo "Number of assignments cannot be negative" >&2
    exit 1
fi

if [ ! -r "students.csv" ]; then
    echo "students.csv either doesn't exist or is unreadable" >&2
    exit 1
fi

numberOfAssignments=$1

tempfile1=$(mktemp)
tempfile2=$(mktemp)

cp "students.csv" $tempfile1

num=1

while [ $num -le $numberOfAssignments ]; do
    if [ ! -r "a${num}.csv" ]; then
        echo "Assignment $num.csv does not exist or is unreadable" >&2
    fi
    join -t ',' $tempfile1 "a${num}.csv" > $tempfile2
    mv $tempfile2 $tempfile1
    num=$((num + 1))
done

mv $tempfile2 "totals.csv"
