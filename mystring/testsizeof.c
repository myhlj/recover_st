#include <stdlib.h>
#include <string.h>

int main()
{
	char* str="123456";
	int size = sizeof(str);
	printf("%d\n",size);

	char str1[5]="1234";
	size=sizeof(str1);
	printf("%d\n",size);

	size = strlen(str);
	printf("%d\n",size);
	return 0;
}
