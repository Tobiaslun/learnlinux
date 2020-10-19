virtual-node:
以统一核心封装不同文件的差别，方便编程
app->v-node->i-node(物理细节)

open "path" 通过path找到文件对应的i-node
1.以路径定基本目录项->将i-node导入内存，并生成一个对应的v-node
2.将v-node的地址添加入系统打开文件列表，形成新表项。该表项中存进程访问文件的权限，位置及对应v-node的地址
3.在用户进程打开文件列表中新增项包含该文件在系统打开文件列表中表项的地址。

用户访问时的顺序：
用户打开文件列表->系统打开文件列表->v-node->i-node->data
 (proc1、proc2)  (FILE* 权限，位置）（公用） ...     ..
同一文件在系统中被分进程访问时v-node和i-node是唯一的，系统打开列表文件描述符是独立的。

mkdir week4-1
cp ./week3/*.h ./week4-1
cd week4-1
vi 4-1.c
gcc 4-1.c -o 4-1
cp /proc/locks ./source
./4-1 source obj.bak

4-1.c：实现复制文件
#include "ch2.h"
int main(int argc,char **argv)
{
	int n,from,to;
	char buf[1024];
	if(argc!=3)
	{
		printf("Usage: %s from-file to file\n",argv[0]);
		exit(1);
	}
	if((from=open(argv[1],O_RDONLY))<0)
	{
		printf("Usage: %s from-file to file\n",argv[1]);
		exit(1);
	}
	if((to=open(argv[2],O_WRONLY|O_CREAT|O_APPEND,0644))<0)
	{
		printf("Usage: %s from-file to file\n",argv[2]);
		exit(1);
	}
	while((n=read(from,buf,sizeof(buf)))>0)
		write(to,buf,n);
	close(from);
	close(to);
	return 0;
}	

4-2.c:
#include "ch2.h"
char buf1[]="abcdefghij";
char buf2[]="0123456879";
int main(void)
{
	int fd;
	if((fd=open("file.hole",O_WRONLY|O_CREAT,0644))<0)
		err_exit("Create error!");
	if(write(fd,buf1,10)!=10)
		err_exit("Write error!");
	if(lseek(fd,40,SEEK_SET)==-1)
		err_exit("Lseek error!");
	if(write(fd,buf2,10)!=10)
		err_exit("Write error!");
	return 0;
}

darren@darren-virtual-machine:~/week4-1$ od -c file.hole
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
0000040  \0  \0  \0  \0  \0  \0  \0  \0   0   1   2   3   4   5   6   8
0000060   7   9

4-3.c:
#include "ch2.h"
char buf1[]="abcdefghij";
char buf2[]="0123456879";
int main(void)
{
	int fd;
	if((fd=open("file.hole",O_WRONLY|O_CREAT|O_APPEND,0644))<0)
		err_exit("Create error!");
	if(write(fd,buf1,10)!=10)
		err_exit("Write error!");
	if(lseek(fd,40,SEEK_SET)==-1)
		err_exit("Lseek error!");
	if(write(fd,buf2,10)!=10)
		err_exit("Write error!");
	return 0;
}

darren@darren-virtual-machine:~/week4-1$ od -c file.hole
0000000   a   b   c   d   e   f   g   h   i   j   0   1   2   3   4   5
0000020   6   8   7   9


4-4.c:
#include "ch2.h"
int main()
{
	int fd1,fd2;
	char buf[6];
	memset(buf,0,6);
	fd1=open("./file.hole.2",O_RDONLY);
	fd2=open("./file.hole.2",O_RDONLY);
	printf("fd1=%d,fd2=%d\n",fd1,fd2);
	lseek(fd1,4,SEEK_SET);
	read(fd2,buf,5);
	printf("fd2 is %s\n",buf);
	return 0;
}

4-5.c:
#include "ch2.h"
int main()
{
	int fd1,fd2;
	char buf[6];
	memset(buf,0,6);
	fd1=open("./file.hole.2",O_RDONLY);
	fd2=dup(fd1);
	printf("fd1=%d,fd2=%d\n",fd1,fd2);
	lseek(fd1,4,SEEK_SET);
	read(fd2,buf,5);
	printf("fd2 is %s\n",buf);
	return 0;
}
od -c flie.hole.2



