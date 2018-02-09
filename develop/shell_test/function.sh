#!/bin/bash
. SvnGitCommit
DIR="./"
FILE=
#####Import Custom Functions

	Copy_to_FileServer "aa" "bb" "cc"
	Calc_md5sum
	DIR=$(pwd)
	FILE=$(ls)
echo "Ending ...."
