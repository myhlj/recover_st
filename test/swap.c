#include <stdlib.h>

#define swap(x,y)\
	x = x+y;\
	y = x-y;\
	x = x-y;
int main()
{
	int a=3;
	int b=2;
	swap(a,b);
	printf("%d,%d\n",a,b);
	return 0;
}
