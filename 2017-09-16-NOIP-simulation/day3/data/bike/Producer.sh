#!/bin/bash

prob="bike"

for((i=1;i<=20;i++))
do
	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
	echo "make " ${prob}${i} "..."
done

