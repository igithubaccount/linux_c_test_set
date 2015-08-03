#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t tid1;
pthread_t tid2;

void *thrd_func1(void *arg);
void *thrd_func2(void *arg);

int main()
{
	if(pthread_create(&tid1,NULL,thrd_func1,NULL)!=0)
	{
		printf("create pthread 1 error\n");
		exit(1);
	}
	if(pthread_create(&tid2,NULL,thrd_func2,NULL)!=0)
	{
		printf("create pthread 2 error\n");
		exit(1);
	}

	if(pthread_join(tid1,NULL)!=0)
	{
		printf("join thread 1 error\n");
		exit(1);
	}
	else 
		printf("Thead 1 joined\n");
	if(pthread_join(tid2,NULL)!=0)
	{
		printf("join thread 2 error\n");
		exit(1);
	}
	else 
		printf("Thread 2 joined\n");

	return 0;
}

void *thrd_func1(void* arg)
{
	pthread_setcancelstate(NULL,NULL);
	while(1)
	{
		printf("Thread 1 is running\n");
		sleep(1);
	}
	pthread_exit((void*)0);
}

void *thrd_func2(void* arg)
{
	printf("Thread 2 is running \n");
	sleep(5);
	if(pthread_cancel(tid1)==0)
		printf("send cancel cmd to thread 1 \n");
	pthread_exit((void*)0);
}
