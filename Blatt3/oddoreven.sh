#! /bin/bash

if !(($1 % 2))
then 
	echo "$1 ist gerade"
else
	echo "$1 ist ungerade"
fi
