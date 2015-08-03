#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int main()
{
	pthread_t thread_id;
	thread_id=pthread_self();
	printf("Thread ID:%lu.\n",thread_id);

	if(pthread_equal(thread_id,pthread_self()))
	{
		printf("Equal\n");
	}else{
		printf("No Equal\n");
	}

	return 0;
}
