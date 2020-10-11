1、文件系统：由字符路径转化为i-node节点号->物理地址
2、目录（文件）：从路径中取关键字检索出i-node号，由index-node（索引节点）完成
	1）安全、权限控制。2）通过地址表访问物理块。


管道文件：进程间通信
进程号是动态给予的

sleep 300|sleep 500&
&表示在后台运行
pgrep -l sleep
搜索当前进程,关键字为sleep。
ls /proc
ll /proc/19750/fd
ll /proc/19751
ls /proc/
kill 19750


vi 2-3.c
gcc 2-3.c -o 2-3
./2-3
其中2-3.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int ret;
	ret=write(1,"hello world!\n",13);
	printf("ret=%d\n",ret);
}

vi 2-3.c
gcc 2-3.c -o 2-3
./2-3
打开另一个终端
strace ./2-3可追踪进程，按ctrl+c停止追踪
ps -ef 查看进程信息如进程号
注：2-3.c改成：
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int ret;
	ret=write(0,"hello world!\n",13);
	printf("ret=%d\n",ret);
	sleep(500);
}

mv命令作用：mv 2-4.h 2-4.c把2-4.h改名成2-4.c

vi 2-4.c
gcc 2-4.c -o 2-4
./2-4
ps -ef
ls -l /proc/进程号/fd
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd，i;
	char buf[100];
	fd=open("./test.data",O_CREAT|O_WRONLY,0644);
	for(i=0;i<100;i++)
		buf[i]=i;
	printf("process %d:before writing i=%d\nfile description=%d\n",getpid(),i,fd);
	i=write(fd,buf,sizeof(buf));
	printf("after i=%d\n",i);
	sleep(5000);
	return 0;
}

uname -a

echo $PATH>path.bak备份
PATH=$PATH:/home/week2/code
echo $PATH