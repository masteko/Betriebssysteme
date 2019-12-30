#! /bin/bash

# all files get zippend own their own
gzip -k *.txt

# zip them all together
mkdir testdir && cp *.txt ./testdir/ && gzip -k testdir

