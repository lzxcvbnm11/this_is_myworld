#include <stdio.h>

int main(int argc, char *argv[])
{
	char **p = argv;
	printf("%p\n",p);
	printf("%s\n",*p);
	printf("%ss\n",*p++);
	printf("%p\n",p);
	return 0;
}
