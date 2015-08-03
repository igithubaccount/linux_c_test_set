#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h> //open() close()
#include<unistd.h> //read() write()

#define LED_ON 1
#define LED_OFF 0

int main()
{
	int fd,i;
	fd=open("/dev/leds",0);
	if(fd<0)
	{
		printf("open device /dev/leds error!\n");
	}
	else
	{
		while(1)
		{
			for(i=0;i<4;i++)
			{
				printf("led %d is on!\n",i);
				ioctl(fd,LED_ON,i);
				sleep(1);
				printf("led %d is off!\n",i);
				ioctl(fd,LED_OFF,i);
				sleep(1);
			}
			if(i==4)
				i=0;
		}
		close(fd);
	}
	return 0;
}
