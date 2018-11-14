#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t>0)
    {
        int n;
        scanf("%d",&n);
        int sol = n/2 +1;
        printf("%d\n",sol);
        t--;
    }
    return 0;
}

