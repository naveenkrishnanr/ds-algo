#include <stdio.h>

void reset(int *b)
{
    int i;
    for(i=0;i<101;i++){
        b[i]=0;
    }
}
int sum(int *b){
    int i,s=0;
    for(i=0;i<101;i++)
        s+=b[i];
    return s;
}

int main(void)
{
    int a[101];
    int t,np,nr,total;

    scanf("%d",&t);

    while(t>0)
    {
        scanf("%d",&np);
        total=nr=np;
        reset(a);
        while(np>0)
        {
            int temp;
            scanf("%d",&temp);
            a[temp]++;
            np--;
        }

        while(nr>0)
        {
            int temp;
            scanf("%d",&temp);
            int i=temp;

            while(a[i]==0 && i>=0)
            {
                i--;
            }
            if(i>=0)
                a[i]--;

            nr--;
        }

        printf("%d\n",total-sum(a));
        t--;
    }

    return 0;
}

