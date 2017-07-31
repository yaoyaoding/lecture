#!/bin/bash

prob="solar"

for((i=1;i<=10;i++))
do
	echo ./${prob} "<" ${prob}${i}.in ">" ${prob}${i}.ans
	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
	echo "make " ${prob}${i} "..."
done

