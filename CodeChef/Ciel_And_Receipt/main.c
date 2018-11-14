#include <stdio.h>

int two_pow[13] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048};

int recursiveCheck(int itemsCount,int p)
{
    int i;
    for(i=12;i>=0;i--)
        if(two_pow[i]<=p){
            p-=two_pow[i];
            break;
        }

    if(p==0)
        return itemsCount;


    return recursiveCheck(++itemsCount,p);
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t>0)
    {
        int p;
        scanf("%d",&p);
        printf("%d\n",recursiveCheck(1,p));
        t--;
    }

    return 0;
}

