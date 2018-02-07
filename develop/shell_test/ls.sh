#!/bin/bash
TXT_PATH=`pwd`
echo "$(TXT_PATH)"
CC=gcc
TXT=
echo "$(TXT_PATH)"
cd $(TXT_PATH)/../
CC = `ls`
for var in `ls`
do
	echo "$(CC)"
done
echo "cd $(TXT_PATH)"
cd -
