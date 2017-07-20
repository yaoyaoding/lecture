#!/bin/bash

prob="seq"

for((i=1;i<=10;i++))
do
	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
	echo "make " ${prob}${i} "..."
done

