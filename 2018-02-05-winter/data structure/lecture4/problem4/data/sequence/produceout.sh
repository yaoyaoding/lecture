#!/bin/bash

prob="sequence"

for((i=0;i<=10;i++))
do
	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
	echo "make " ${prob}${i} "..."
done

