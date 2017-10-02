#!/bin/bash

prob="contest"

for((i=1;i<=50;i++))
do
	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
	echo "make " ${prob}${i} "..."
done

