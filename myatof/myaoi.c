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

int myatoi_2(const char* s){
    assert(s != NULL);
    int ispnum = 0;
    if(*s == '-'){
        ispnum = 1;
        s++;
    }
    int ret = 0;
    while(*s != '\0'){
        ret = ret * 10 + (*s - '0');
        s++;
    }
    if(!ispnum)
        ret = -1 * ret;
    return ret;
}

char* mystrcpy(char* dest,char* src){
    assert(dest != NULL);
    assert(src != NULL);
    
    char* temp = dest;
    while(*src != '\0'){
        *dest++ = *src++;
    }
    *dest='\0';
    return temp;
}

char* mystrcat(char* dest,char* src){
    assert(dest != NULL);
    assert(src != NULL);

    char* temp = dest;
    while(*dest != '\0'){
        dest++;
    }
    while(*src != '\0'){
        *dest++ = *src++;
    }
    *dest = '\0';
    return temp;
}

int main()
{
	const char* sample = "-1235";
	int ret = myatoi(sample);
	printf("%d\n",ret);

    char dest[10] = {0};
    char src[5] = "12345";
    char* rest = mystrcpy(dest,src);
    printf("%s\n",rest);
    printf("%s\n",dest);


    char* sec="lj";
    rest = mystrcat(dest,sec);
    printf("%s\n",rest);
    printf("%s\n",dest);
	return 0;
}
