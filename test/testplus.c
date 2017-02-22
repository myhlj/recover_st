#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a = (2>2) ? 1:0;
    ++a;
    printf("%d\n",a);
    return 0;
}
