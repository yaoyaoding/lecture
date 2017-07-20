#!/bin/bash


for((i=1;;i++))
do
	./yprod.py > input
	./A < input > A.out
	./B < input > B.out 
	diff A.out B.out  > /dev/null
	if [ $? -ne 0 ]
	then
		echo $i WA
		exit
	else
		echo $i AC
	fi
	
done
