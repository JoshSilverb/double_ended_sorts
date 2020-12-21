#!/bin/bash

for t in ./tests
do
    echo "Running $t"
    ./t
    echo "$t completed successfully"
done