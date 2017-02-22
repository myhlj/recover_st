#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char* pstr = (char*)malloc(10);	
    strcpy(pstr,"123");
	printf("hello world");
	return 0;
}
