#include <stdio.h>
#include <math.h>
long long int reduce(long long int n,long long int i)
{
    while(n%i==0)
        n/=i;
    return n;
}
long long int hcf(long long int a,long long int b)
{
    long long int num1,num2;
    if(a>b)
    {
        num1=a;
        num2=b;
    }
    else
    {
        num1=b;
        num2=a;
    }
    while(num2!=0)
    {
        long long int temp = num2;
        num2=num1%num2;
        num1=temp;
    }

    return num1;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        //        printf("%lld\n",hcf(a,b));
        int flag=1;

        long long int h=hcf(a,b);

        if(h==b)
        {
            printf("Yes\n");
            t--;
            continue;
        }

        b/=h;
        if(h==1)
        {
            if(b==1){
                printf("Yes\n");
                t--;
                continue;
            }
            else {
                printf("No\n");
                t--;
                continue;
            }
        }

        if(h<=b)
        {
            if(h%2==0)
            {
                h=reduce(h,2);
                b=reduce(b,2);
            }
            long long int j;
            for(j=3;j<=sqrt(h);j+=2)
            {
                if(h%j==0)
                {
                    h=reduce(h,j);
                    b=reduce(b,j);
                }
            }
            if(h>2)
                b=reduce(b,h);

            if(b>1)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else
        {
            a/=h;
            if(b%2==0)
            {
                if(h%2!=0&&a%2!=0){
                    flag=0;
                }
                b=reduce(b,2);
            }

            if(flag)
            {
                long long int j=3;
                for(j=3;j<=(long long int)(sqrt(b));j+=2)
                {
                    if(b%j==0)
                    {
                        if(h%j!=0&&a%j!=0)
                        {
                            flag=0;
                            break;
                        }
                        b=reduce(b,j);
                    }
                }
                if(b>2&&h%b!=0)
                    if(a%b!=0)
                        flag=0;
            }
            flag?printf("Yes\n"):printf("No\n");
        }
        t--;
    }
    return 0;
}
