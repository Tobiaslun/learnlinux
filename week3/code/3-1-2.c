#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	FILE *fp=fopen("./ftest.txt","w");
	char buf[80];
	memset(buf,0,sizeof(buf));
	fgets(buf,sizeof(buf),stdin);
	printf("\nthe string is %s \n",buf);
	fwrite(buf,sizeof(buf),1,fp);
	fclose(fp);
	return 0;
}

