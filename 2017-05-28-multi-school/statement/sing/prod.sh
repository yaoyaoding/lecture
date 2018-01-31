#!/bin/bash

prog="sing"

for((i=1;i<=10;i=i+1))
do
	echo "make  $prog${i} ..."
	\time -f "Time:%e" ./$prog < ${prog}${i}.in > ${prog}${i}.ans
done


