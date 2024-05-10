#!/bin/bash

> ./data.txt

for filename in ./bin/*; do
    echo -n "$filename," >> ./data.txt
    mpirun -N 8 --oversubscribe "$filename" 10000000  >> ./data.txt
done

for filename in ./bin/*; do
    echo -n "$filename," >> ./data.txt
    mpirun -N 8 --oversubscribe "$filename" 100000000  >> ./data.txt
done

for filename in ./bin/*; do
    echo -n "$filename," >> ./data.txt
    mpirun -N 8 --oversubscribe "$filename" 1000000000  >> ./data.txt
done

for filename in ./bin/*; do
    echo -n "$filename," >> ./data.txt
    mpirun -N 8 --oversubscribe "$filename" 10000000000  >> ./data.txt
done