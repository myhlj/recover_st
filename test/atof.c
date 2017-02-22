#include <stdlib.h>


double atof(const char* src)
{
	double res = 0.0;
	while(*src != '\0')
	{
		if(*src=='.')
		{
			src++;
			break;
		}

		res = res * 10 + (*src - '0');
		src++;
	}

	double temp = 10.0;
	while(*src != '\0')
	{
		res = res + (*src - '0')/temp;
		temp *= 10;
		src++;
	}

	return res;
}

int main()
{

	char* src = "100.789";
	double res = atof(src);
	printf("%lf\n",res);
	return 0;
}

