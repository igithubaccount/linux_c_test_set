#include<stdio.h>
static char buff[256];
static char* string;
int main(void)
{
	printf("Please input a string");
	gets(buff);
	printf("\nYou string is%s\n",string);
	return 0;
}
