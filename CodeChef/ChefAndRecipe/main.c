#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t>0){
        int n,a,min=100000;
        long long int sum=0;
        scanf("%d",&n);
        while(n>0){
            scanf("%d",&a);
            sum+=a;

            if(a<min)
                min=a;
            n--;
        }
        if(1==min)
            printf("-1\n");
        else
            printf("%lld\n",(sum-min)+2);

        t--;
    }


    return 0;
}

