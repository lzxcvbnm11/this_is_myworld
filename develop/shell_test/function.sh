#!/bin/bash

DIR="./"
FILE=
#####Import Custom Functions
. SvnGitCommit

	Copy_To_FileSever "aa" "bb" "cc"
	Calc_md5sum_shalsum
	DIR=$(pwd)
	FILE=$(ls)
echo "ls = ${FILE}"
echo "this is pwd = ${DIR}"
echo "Ending ...."
