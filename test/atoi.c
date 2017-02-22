#include <stdlib.h>

int atoi(const char* src)
{
	int res = 0;
	while(*src != '\0')
	{
		res = res * 10 + (*src - '0');
		src++;
	}
	return res;
}

int main()
{
	char* src = "123456789";
	int res = atoi(src);
	printf("%d\n",res);
	return 0;
}
