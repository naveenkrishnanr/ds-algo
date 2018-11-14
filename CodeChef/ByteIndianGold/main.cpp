#include <stdio.h>

long long int arr1[10000001];
long long int arr2[10000001];
long long int arr3[10000001];
long long int arr4[10000001];
long long int arr5[10000001];
long long int arr6[10000001];
long long int arr7[10000001];
long long int arr8[10000001];
long long int arr9[10000001];
long long int arr10[10000001];

long long int* arr[10];

long long int maxValue(long long int coin)
{

    if(coin == 2)
        return 2;

    if(coin == 0)
        return 0;

    if(coin == 1)
        return 1;

    if(coin < 10000001 && arr[(coin/10000001)+1][coin % 10000001] != 0)
        return arr[(coin/10000001)+1][coin % 10000001];

    long long int sum = maxValue(coin/2) + maxValue(coin/3) + maxValue(coin/4);
    long long int res = sum > coin ? sum : coin;

    if(coin < 10000001){
        arr[(coin/100000001)+1][coin % 100000001] =  res;
    }

    return res;
}

int main(int argc, char *argv[])
{
    arr[0] = arr1;
    arr[1] = arr2;
    arr[2] = arr3;
    arr[3] = arr4;
    arr[4] = arr5;
    arr[5] = arr6;
    arr[6] = arr7;
    arr[7] = arr8;
    arr[8] = arr9;
    arr[9] = arr10;

    int i = 0;

    while(i<10)
    {
        i++;
        long long int d;
        scanf("%lld",&d);
        printf("%lld\n",maxValue(d));
    }

    return 0;
}
