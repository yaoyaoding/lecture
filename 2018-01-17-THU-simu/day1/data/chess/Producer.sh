#!/bin/bash

prob="chess"

for((i=0;i<=10;i++))
do
	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
	time ./his < ${prob}${i}.in > ${prob}${i}.his.out
	./spj ${prob}${i}.in ${prob}${i}.ans ${prob}${i}.his.out 10 ${prob}${i}.score ${prob}${i}.log
#	time ./${prob} < ${prob}${i}.in > ${prob}${i}.ans
#	echo "make " ${prob}${i} "..."
done

