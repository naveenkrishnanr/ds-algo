#include <stdio.h>
const int  limit=1000003;
const int tlimit=10000000;
int moduloCal[10000] = {1};
long long int powMod(int i)
{
    if(moduloCal[i]!=0)
        return moduloCal[i];

    int j;
    long long int m = 1;
    for(j=0;j<=i;j++){
        if(moduloCal[j]!=0)
            m=moduloCal[j];
        else{
            m*=999973;
            m%=limit;
            moduloCal[j]=m;
        }
    }
    return m;
}

long long int combination(int n,int r)
{

    int numberArray[10000] = {1};

    if(r>n)
        return 0;
    else if(r==n)
        return 1;

    int i;
    int j;
    int p=0;

    int n_r = n-r;
    int low = n_r > r ? n_r : r;
    int high = n-low;

    for(i=n;i>low;i--)
    {
        long long int carry = 0;
        for(j=0;j<=p;j++)
        {
            numberArray[j]*=i;
            numberArray[j]+=carry;
            if(numberArray[j] >= tlimit)
            {
                carry = numberArray[j];
                numberArray[j]=numberArray[j]%tlimit;
                carry /= tlimit;
                if(j==p)
                    p++;
            }
            else
                carry=0;
        }
    }

    for(i=2;i<=high;i++)
    {
        long carry = 0;
        for(j=p;j>=0;j--)
        {
            long long temp = carry*tlimit+numberArray[j];
            carry = temp%i;
            numberArray[j]=temp/i;
            if(numberArray[j]==0)
                if(j==p)
                    p--;
        }
    }

    long long int modulo=0;

    for(i=0;i<=p;i++)
    {

        long long int val = powMod(i);

        modulo+= (val*(numberArray[i]%limit));
        modulo%=limit;
    }

    return modulo;

}

int lucasTheorem(long long int n,long long int r)
{
    long long int p=1;
    while(n&&r)
    {
        int N=n%limit;
        int R=r%limit;
        p*=combination(N,R);
        p%=limit;
        n/=limit;
        r/=limit;
    }
    return p;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t>0)
    {
        long long int n,l,r;
        scanf("%lld%lld%lld",&n,&l,&r);

        int num = r-l+1;

        long long int count = lucasTheorem(n+num,num);

        if(count==0)
            count=limit-1;
        else
            count--;

        printf("%lld\n",count);
        t--;
    }
    return 0;
}
