#include "ch2.h"
int main()
{
	int fd;
	fd=open("./test.txt",O_RDONLY);
	printf("fd=%d\n",fd);
	return 0;
}
