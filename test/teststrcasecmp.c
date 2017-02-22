#include <string.h>
#include <stdlib.h>

int main()
{
	char* str1="abcd";
	char* str2="abcdef";

	int res = strcasecmp(str1,str2);
	printf("%d\n",res);
	return 0;
}
