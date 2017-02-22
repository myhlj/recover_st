#include <stdlib.h>

char* strcpy(char* strDest,const char* strSrc)
{
	if(strDest==NULL || strSrc==NULL)
		return;
	char* add = strDest;
	while(*strSrc!='\0')
	{
		*strDest++ = *strSrc++;
	}
	
	return add;
}


int main()
{
	char strDest[100]={0};
	char strSrc[7]="123456";
	strcpy(strDest,strSrc);
	printf("%s\n",strDest);
	return 0;
}
