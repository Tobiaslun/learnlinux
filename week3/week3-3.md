进程的运行=计算任务（指令）+I/O任务（资源）
			CPU				外设

外设将数据映射到内存中，cpu在内存中读取数据（称为文件的内存映像）

进程间通信：
OS内核转发 ns
共享内存 ns
共享文件 ms

（int fd）基于文件描述符
（FILE* pt）基于流


文件操作：
由OS提供的基于文件描述符，更为底层，windows不支持
由C标准函数库提供的，基于FILE流，API，FILE是对包括文件描述符在内的底层文件信息为封装。



vi 3-1-1.c
gcc -g -Wall 3-1-1.c -o 3-1-1

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd=open("./test.txt",O_CREAT,0644,"test");
	printf("file descriptor=%d\n",fd);
	close(fd);
	return 0;
}

vi 3-1-2.c
gcc -g -Wall 3-1-2.c -o 3-1-2
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	FILE *fp=fopen("./ftest.txt","w");
	char buf[80];
	int ret=0;
	memset(buf,0,sizeof(buf));
	fgets(buf,sizeof(buf),stdin);
	printf("\nthe string is %s \n",buf);
	ret=fwrite(buf,sizeof(buf),1,fp);
	printf("number of item write to file=%d\n",ret);
	fclose(fp);
	return 0;
}



