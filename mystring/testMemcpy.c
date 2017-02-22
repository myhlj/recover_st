#include "stdlib.h"
#include "string.h"

int main()
{
	int *p = (int*)malloc(2 * sizeof(int));

	int sample1 = 1;
	int sample2 = 2;

	memcpy(p,&sample1,sizeof(int));
	memcpy(p+4,&sample2,sizeof(int));

	printf("%d\n",*p);
	printf("%d\n",*(p+4));
	
	int *p1 = (int*)malloc(3 * sizeof(int));


	

	int sample3 = *(p+4);

	printf("%d\n",sample3);

	memcpy(p1,&sample2,sizeof(int));
	memcpy(p1+4,&sample3,sizeof(int));
	memcpy(p1+8,&sample1,sizeof(int));

//	free(p);
//	p = NULL;

	printf("%d\n",*p1);
	printf("%d\n",*(p1+4));
	printf("%d\n",*(p1+8));
//	free(p1);

	return 0;
}
