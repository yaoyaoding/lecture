#!/bin/bash

for((i=1;;i=i+1))
do
	./yprod.py > input
	./setmod < input > A.out
	./his < input > B.out
	diff A.out B.out > /dev/null
	if [ $? -ne 0 ]
	then
		echo $i N
		exit
	else
		echo $i Y
	fi
done
