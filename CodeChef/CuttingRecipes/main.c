#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t>0){
        int n;
        scanf("%d",&n);
        int tn=n;
        int a[51]={};
        int i=0;
        int min=1001;
        while(tn>0){
            int temp;
            scanf("%d",&temp);
            if(temp < min)
                min=temp;
            a[i++]=temp;
            tn--;
        }
        int gcd = 1;
        while(min>1){
            int j=0;
            int f = 1;
            for(j=0;j<n;j++){
                if(a[j] % min != 0){
                    f=0;
                    break;
                }
            }
            if(f==1){
                gcd*=min;
                break;
            }
            f=1;
            min--;
        }
        for(i=0;i<n-1;i++){
            printf("%d ",a[i]/gcd);
        }
        printf("%d\n",a[i]/gcd);
        t--;
    }

    return 0;
}

