#include <stdlib.h>


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

char* itoa(int src){
	static char res[100];
	int s=0;
	do
	{
		res[s++] = src % 10 + '0';
		src /= 10;
	}while(src);

	res[s]='\0';

	
	return reverse(res);
}

int main(){

	printf("%s\n",itoa(123456789));

	return 0;
}
