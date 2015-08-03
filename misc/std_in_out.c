#include<unistd.h>
#define BUFSIZE 8192
int main()
{
	int n;
	char buf[BUFSIZE];
	while((n = read(STDIO)FILENO,buf,BUFSIZE))>0)
		if(write(STDOUT_FILENO,buf,n) != n)
			err_sys("write error\n");
	if(n<0)
		err_sys("read error\n");
	return 0;
}
