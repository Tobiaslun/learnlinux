#include "ch2.h"
int main()
{
	FILE *fp;
	fp=fopen("./test.txt","r");
	printf("fd=%d\n",fp->_fileno);
	return 0;
}
