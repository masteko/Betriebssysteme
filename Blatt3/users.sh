#! /bin/bash

users=0
index=0

for user in "$@"
do
	if [ $(cut -d ":" -f 1 /etc/passwd | grep $user | wc -l) -ge 1 ]
	then
		users=$((users+1))
	fi
	index=$((index+1))
done

exit $users
