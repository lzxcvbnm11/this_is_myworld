#!/bin/basha
MAX_OA=0
read MAX_OA
echo "${MAX_OA}"

if [ ${MAX_OA} -gt 9 -o ${MAX_OA} -lt 2 ];then
	echo "it is no equle"
else
	clear
	for ((i=0;i<${MAX_OA};i++))
	do
		for ((j=i;j<${MAX_OA}-1;j++))
		do
			echo -n " "
		done

		for ((j=0;j<=i;j++))
		do
			echo -n "X "
		done
		echo ""
	done

	for ((i=${MAX_OA}-2;i>=0;i--))
	do
		for ((j=i;j<${MAX_OA}-1;j++))
		do
			echo -n " "
		done

		for ((j=0;j<=i;j++))
		do
			echo -n "X "
		done
		echo ""
	done
fi
