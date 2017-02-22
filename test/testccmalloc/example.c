#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char* str = (char*)malloc(100);
    strcpy(str,"1243325432");
    printf("%s\n",str);
    return 0;
}
