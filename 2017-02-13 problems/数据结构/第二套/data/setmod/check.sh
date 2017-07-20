#!/bin/bash

prob="setmod"

for((i=1;i<=3;i++))
do
	time ./${prob} < ${prob}${i}.in > "A.out"
	time ./${prob}_brute < ${prob}${i}.in > "B.out"
	diff A.out B.out > /dev/null
	if [ $? -ne 0 ]
	then
		echo N $i
		exit
	else
		echo Y $i
	fi
done

rm A.out B.out
