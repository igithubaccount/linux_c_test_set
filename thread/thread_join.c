#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

void *thrd_func1(void *arg);
void *thrd_func2(void *arg);

int main(void)
{
	pthread_t tid1,tid2;
	void* tret;
	if(pthread_create(&tid1,NULL,thrd_func1,NULL)!=0)
	{
		printf("Create thread 1 error\n");
		exit(1);
	}
	if(pthread_create(&tid2,NULL,thrd_func2,NULL)!=0)
	{
		printf("Create thread 2 error\n");
		exit(1);
	}
	if(pthread_join(tid1,&tret)!=0)
	{
		printf("join thread 1 error\n");
		exit(1);
	}
	printf("thread 1 exit code %d\n",(int *)tret);
	if(pthread_join(tid2,&tret)!=0)
	{
		printf("join thread 2 error\n");
		exit(1);
	}
	printf("thread 2 exit code %d\n",(int *)tret);

	return 0;
}	

void *thrd_func1(void* arg)
{
	printf("Thread 1 returning \n");
	return ((void *)1);
}

void *thrd_func2(void* arg)
{
	printf("Thread 2 exiting \n");
	pthread_exit ((void *)2);
}
