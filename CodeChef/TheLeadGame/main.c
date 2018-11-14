#include <stdio.h>

int main(void)
{

    int n;
    scanf("%d",&n);

    int max = 0;
    int p = 1;
    int p1=0,p2=0;
    int i;
    for(i = 0; i < n; i++ )
    {
        int p3,p4;
        scanf("%d %d",&p3,&p4);

        p1+=p3;
        p2+=p4;
        if(p1 > p2)
        {
            if(max < (p1-p2)){
                max =  (p1-p2);
                p = 1;
            }
        }
        else
        {
            if(max <  (p2-p1)){
                max = (p2-p1);
                p = 2;
            }
        }
    }

    printf("%d %d",p,max);

    return 0;
}

