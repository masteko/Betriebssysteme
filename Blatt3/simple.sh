#! /bin/bash

cp /etc/passwd ./$(date +%A)passwd
echo "$(cut -d ":" -f 1 $(date +%A)passwd | sort)" > $(date +%A)passwd
