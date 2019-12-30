# Übungsblatt 3

## Aufgabe 1

```bash
#! /bin/bash

cp /etc/passwd ./$(date +%A)passwd
echo "$(cut -d ":" -f 1 ./$(date +%A)passwd | sort)" > ./$(date +%A)passwd
```


## Aufgabe 2
- a) 

```bash
#! /bin/bash

filecount=$(cd $HOME && ls -l | grep "total.*" | cut -d " " -f 2)
echo "Der User $LOGNAME hat $filecount Dateien in seinem Homeverzeichnis $HOME"
```

- b)

```bash
#! /bin/bash

val="$1"
output=${val##/*/}
echo "$output"
```

- c)



## Aufgabe 3
- a)

```bash
#! /bin/bash

if !(($1 % 2))
then
        echo "$1 ist gerade"
else
        echo "$1 ist ungerade"
fi
```

- b)

```bash
#! /bin/bash

echo "obase=2;$1" | bc
```

## Aufgabe 4
- a)

```bash
#! /bin/bash

i=1
sum=0
while [ $i -le $1 ]
do
        sum=$((sum+i))
        i=$((i+1))
done

echo "Summe: $sum"
``` 

- b) 

```bash
#! /bin/bash

# all files get zippend own their own
gzip -k *.txt
```

- c)

```bash
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
```

- d)

```bash
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
```