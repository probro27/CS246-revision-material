#!/bin/bash

numberOfArguments=$#

if [ $numberOfArguments -lt 1 ]; then
    echo "Parameter number is less than 2" <&2
    exit 1
fi

num=1

while [ $num -le $numberOfArguments ]; do
    if [ ! -r ${!num} ]; then
        echo "File does not exist or isn't readable" <&2
    fi
    wc -l < ${!num}
    num=$((num + 1))
done

exit 0
