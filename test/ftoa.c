#include <stdlib.h>
#include <math.h>
#include <string.h>

static const double flag = 0.000001;

char* reverse(char* src)
{
	char* head = src;
	char* tail = src;
	while(*tail)
		tail++;
	--tail;

	char temp;
	while(tail > head)
	{
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}
	return src;
}

char* ftoa(double src)
{
	//分离整数和小数
	long int_part = (long)src;
	double float_part = src - int_part;

	char int_res[32]={0};
	//转整数
	int i=0;
	do{
		int_res[i++] = int_part % 10 + '0';
		int_part /= 10;
	}while(int_part);

	//反转
	reverse(int_res);
	//小数部分-取整小数,判断右多少个小数位
	float_part = fabs(float_part);
	/*
	while(float_part - (long)(float_part) > 0)
	{
		printf("%lf\n",float_part - (long)(float_part));
		float_part *= 10;
	}
	*/

	while(1)
	{
		printf("%lf\n",float_part);
		printf("%d\n",(long)(float_part));
		printf("%lf\n",float_part - (long)(float_part));
		sleep(2);
		if(float_part - (long)(float_part) <= flag)
			break;
		float_part *= 10;
	}

	long temp = (long)float_part;
	char float_res[32]={0};
	i=0;
	do{
		float_res[i++] = temp % 10 + '0';
		temp /= 10;
	}while(temp);

	printf("%s\n",float_res);
	static char res[100];
	i = strlen(int_res);
	int_res[i] = '.';
	strcpy(res,int_res);
	strcat(res,float_res);
	return res;
}

int main(){

	double rsc = 99.780267;
	printf("%s\n",ftoa(rsc));
	return 0;
}
