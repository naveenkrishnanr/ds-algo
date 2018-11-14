#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char str[1000001];
int a[1000001];
int b[1000001];
int c[1000001];

long int A(long int index)
{
    if(index<0)
        return 0;
    return a[index];
}

long int B(long int index)
{
    if(index<0)
        return 0;
    return b[index];
}

long int C(long int index)
{
    if(index<0)
        return 0;
    return c[index];
}

int main(int argc, char *argv[])
{
    int stepSize = 2;
    scanf("%s",str);
    long int length = strlen(str);

    for(long int i=0;i<length;i++)
    {
        if(i!=0){
       a[i] = a[i-1];
       b[i] = b[i-1];
       c[i] = c[i-1];
        }
       if(str[i] == 'A')
       {
           if(i==0)
               a[i] = 1;
           else
               a[i] = a[i-1] + 1;
       }
       else if(str[i] == 'B')
       {
           if(i==0)
               b[i] = 1;
           else
               b[i] = b[i-1] + 1;
       }
       else
       {
           stepSize = 3;
           if(i==0)
               c[i] = 1;
           else
               c[i] = c[i-1] + 1;
       }
    }

    long int i = stepSize-1;
    long int count = 0;
    long int j = 0;
    while(j<length)
    {
        if((i-j+1)%stepSize != 0)
        {
            j++;
            continue;
        }

        if(i >= length)
            break;

        if(i-j+1 < stepSize){
            j=0;
            i++;
            continue;
        }

        if(stepSize == 3){
        if((C(i) - C(j-1)) == (B(i) - B(j-1)) && (C(i) - C(j-1)) == (A(i) - A(j-1))){
            count++;
        }
        }
        else{
        if((B(i) - B(j-1)) == (A(i) - A(j-1))){
            count++;
        }
        }
        j++;
    }

    printf("%ld\n",count);

    return 0;
}
