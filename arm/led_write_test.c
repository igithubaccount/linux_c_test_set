#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	char ch[3];
	for(;;)
	{
		fd=open("/dev/leds4",O_WRONLY);
		if(fd==-1)
		{
			perror("open error\n");
			return 0;
		}
		scanf("%s",ch);
		if(write(fd,ch,2)==-1)
		{
			perror("write error\n");
		}
		printf("OK\n");
		close(fd);
		fflush(stdin);

	}
	return 0;
}
