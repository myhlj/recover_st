#include <stdlib.h>
#include <string.h>

int intcmpre(void* num1,void* num2)//最好的实现范式是编写一个和linesearch中比较函数相同的类型的cmpre
{
	return memcmp(num1,num2,sizeof(int));
}

void* linesearch(void* base,void* key,int elemsize,int length,int (*cmpre)(void*,void*))
{
	int i=0;
	for(i;i<length;i++)
	{
		void* addr = (char*)base + i*elemsize;
		if(!cmpre(addr,key))
			return addr;
	}
	return NULL;
}

int strcmpre(void* str1,void* str2)
{
	return memcmp(str1,str2,sizeof(char*));
}

int main()
{
	int example[5]={1,2,3,4,5};
	int key = 3;
	int *result = linesearch(example,&key,sizeof(int),5,intcmpre);
	printf("%d\n",*result);
	
	char* notes[]={"lj","lk","shj"};
	char* strkey="sh";
	char** strresult = linesearch(notes,&strkey,sizeof(char*),3,strcmpre);
	if(strresult!=NULL)
		printf("%s\n",*strresult);
	
	int i=0;
	for(i;i<3;i++)
	{
		printf("%s\n",*(notes+i));
	}


	int a[]={1,3,5};
	for(i=0;i<3;i++)
	{
		printf("%d\n",*(a+i));
	}
	return 0;
}
