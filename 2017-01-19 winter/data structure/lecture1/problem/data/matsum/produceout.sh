#!/bin/bash

prob="matsum"

for((i=1;i<=10;i++))
do
	echo "make " ${prob}${i} "..."
	./${prob} < ${prob}${i}.in > ${prob}${i}.ans
done

