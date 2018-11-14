#include <stdio.h>

int main(void)
{
    char c;
    int a[7];
    int i=0;
    c = getchar();
    while(c!='\n')
    {
        a[i++]=c-48;
        printf("%d",a[i-1]);
        c = getchar();
    }

    if(i==2)
        printf("101");




    return 0;
}

