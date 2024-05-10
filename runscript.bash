#!/bin/bash
for filename in ./bin/*; do
    mpirun -N 8 --oversubscribe "$filename" 10000000  >> ./data.txt
done