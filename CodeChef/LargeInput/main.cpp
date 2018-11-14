#include <stdio.h>


int main(int argc, char *argv[])
{
    int n,k;

    scanf("%d%d",&n,&k);

    int i = 0;
    long int count = 0;
    int t;
    while(i<n)
    {
        scanf("%d",&t);
        if(t%k == 0)
            count = count + 1;
        i++;
    }

    printf("%ld",count);

    return 0;
}
