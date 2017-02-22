#include <stdlib.h>
#include <math.h>
#include <assert.h>

int myatoi(const char* s)
{
	assert(s != NULL);
	int ispnum = 1;
	int ret = 0;

	if(*s == '-')
	{
		ispnum = 0;
		s++;
	}

	while(*s != '\0')
	{
		ret = ret * 10 + (*s - '0');
		s++;
	}
	
	if(!ispnum)
		ret = -1 * ret;
	return ret;
}

int main()
{
	char* sample = "-1235";
	int ret = myatoi(sample);
	printf("%d\n",ret);
	return 0;
}
