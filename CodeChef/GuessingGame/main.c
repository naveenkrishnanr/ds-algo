#include <stdio.h>

int main(void)
{

    int t;

    scanf("%d",&t);
    while(t>0)
    {
        int n,m;

        scanf("%d%d",&n,&m);

        long long den = n*m;
        if(0==den%2)
            printf("1/2");
        else
        {
            printf("%llu/%llu",(den-1)/2,den);
        }
        printf("\n");
        t--;
    }
    return 0;
}

