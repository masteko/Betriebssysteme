#! /bin/bash

i=1
sum=0
while [ $i -le $1 ]
do
	sum=$((sum+i))
	i=$((i+1))
done

echo "Summe: $sum"
