#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
void err_exit(char *s)
{
	printf("Usage:%s is failed!\n",s);
	exit(0);
}
