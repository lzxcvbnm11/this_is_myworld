#/bin/bash
. SvnGitCommit
DIR=$(pwd)/../
POSTFIX=".txt"
POSTFIX_LEN=${#POSTFIX}
FILE=$(ls ${DIR})

for var in ${FILE}
do	
	if [ ${#var} -gt ${POSTFIX_LEN} ]
	then
		len=${#var}
		if [ "${var:${len}-${POSTFIX_LEN}:${POSTFIX_LEN}}" == "${POSTFIX}" ]
		then
			echo "${var}"
		fi
	fi
done
Calc_md5sum

