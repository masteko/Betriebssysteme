#! /bin/bash

case "$1" in
	-S) user=$(cut -d ":" -f 1 /etc/passwd | grep $2 | wc -l);;
	*) echo "wrong option $1" exit 1
esac

if [ $user -ge 1 ]
then 
	echo "user existiert" 
	exit 0
else 
	echo "user exisitert nicht"
	exit 1
fi
