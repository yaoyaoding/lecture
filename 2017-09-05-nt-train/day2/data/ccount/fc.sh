#!/bin/bash


A="a40"
B="a100"

for((i=1;;i++))
do
	./yyprod.py > input
	./${A} < input > A.out
	./${B} < input > B.out
	diff A.out B.out > /dev/null
	if [ $? -ne 0 ]
	then
		echo $i N
		exit
	else
		echo $i Y
		cat input
		cat A.out
	fi
done
