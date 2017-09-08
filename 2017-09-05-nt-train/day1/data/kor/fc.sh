#!/bin/bash

for((i=1;;i++))
do
	./yyprod.py > input
	./kor < input > A.out
	./a10 < input > B.out
	diff A.out B.out > /dev/null
	if [ $? -ne 0 ]
	then
		echo $i N
		exit
	else
		echo $i Y
		cat A.out
	fi
done

