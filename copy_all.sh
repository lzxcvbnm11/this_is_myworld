#!/bin/bash

#echo $#

#echo $*

#echo $1

#echo $2
data="c,cpp,h"
HOUZHUI_C="c"
HOUZHUI_H="h"
HUOZHUI_TXT="txt"

copy_file()
{	
	if [[ `file -b $1` == "data" ]]; then
		echo "----------copy $1 -----------"
        echo `cat $1` > ${1}_c
		rm $1
		mv ${1}_c $1
	fi
	
}


deal_dir()
{
	echo "$1"
	cd $1

	for var in `ls`
	do
		if [ -d $var ]; then
			deal_dir $var
		elif [ -f ${var} ]; then

			filename=$var
			
			if [ ${filename##*.} == "c" ]; then
				copy_file $var
			fi

			if [ ${filename##*.} == "h" ]; then
				copy_file $var
			fi

			if [ ${filename##*.} == "cpp" ]; then
				copy_file $var
			fi
		fi	
	done

	cd ..
}

if [ $# -eq 1 ]; then
	if [ -f $1 ]; then
		copy_file $1	
	elif [ -d $1 ]; then
			if [ -e ${1}_back ]; then
				rm ${1}_back -r
			fi
			echo "copy all file to ${1}_back"
			cp ${1} ${1}_back -rf
			echo "copy over------------"
			deal_dir ${1}_back
	else
		echo "脚本与要拷贝的文件夹必须在同一目录下"
	fi
fi 
