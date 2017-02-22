#include <stdlib.h>
#include <string.h>
/*
char* strcat(char* strDst,const char* strSrc)
{
	if(strDst==NULL)
		return NULL;
	if(strSrc==NULL)
		return strDst;
	char* addr = strDst;
	while(*strDst!='\0')
		strDst++;
	while(*strSrc!='\0')
		*strDst++ = *strSrc++;
	*strDst='\0';
	return strDst;
}
*/
int main()
{
	char strDst[100]="12345678";
	char* str1 = strcat(strDst,"lj");
	printf("%s\n",str1);
	return 0;
}
