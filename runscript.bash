#!/bin/bash

echo "file,threads,n,time" > ./data.txt
for i in 2 4 8; do
    for j in 10000000 100000000 1000000000; do
        for filename in ./bin/*; do
            echo -n "${filename:6},$i,$j," >> ./data.txt
            mpirun -N $i --oversubscribe "$filename" $j  >> ./data.txt
        done
    done
done