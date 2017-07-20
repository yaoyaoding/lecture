#!/bin/bash

prob="mulfunc"

for((i=1;i<=6;i++))
do
	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
	echo "make " ${prob}${i} "..."
done

