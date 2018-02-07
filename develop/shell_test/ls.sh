#!/bin/bash
TXT_PATH=$(pwd)
CC=gcc
TXT=
LS_FILE=
echo "${TXT_PATH}"
cd ${TXT_PATH}/../
echo "$(pwd)"

for var in LS_FILE=`ls`
do
	echo "${var}"
done
cd -
