#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>


double myatof(const char* s)
{
	double temp = 10;
	int ispnum = 1;

	double ret = 0.0;

	if(*s=='-')
	{
		ispnum = 0;
		s++;
	}

	while(*s != '\0')
	{
		if(*s == '.')
		{
			s++;
			break;
		}
		ret = ret * 10 + (*s - '0');
		s++;
	}

	while(*s != '\0')
	{
		ret = ret + (*s - '0')/temp;
		temp *= 10;
		s++;
	}

	if(ispnum)
		return ret;
	else
		return ret * (-1); 
}

int main()
{

	char* sample = "-0.1234509";
	double ret = myatof(sample);

	char* sample1 = "1.4544653";

	printf("%lf\n",ret);
	
	ret = myatof(sample1);
	printf("%lf\n",ret);
	return 0;
}
