#include <stdio.h>

int main(void)
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);

    int ans = a-b;

    if(ans%10 == 9)
        printf("%d",ans-1);
    else
        printf("%d",ans+1);

    return 0;
}

