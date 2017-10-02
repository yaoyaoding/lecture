#!/bin/bash

A="A"
B="B"

for((i=1;;i++))
do
	./yprod.py > input
	./${A} < input > ${A}.out
	./${B} < input > ${B}.out
	diff ${A}.out ${B}.out > /dev/null
	if [ $? -ne 0 ]
	then
		echo $i Y
		exit
	else
		echo $i N
	fi
done

