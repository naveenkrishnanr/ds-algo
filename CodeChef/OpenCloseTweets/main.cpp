#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[1001];

    int j = 0;
    while(j<n+1)
        arr[j++] = 0;

    int l = 0;
    int count = 0;
    while(l < k)
    {
    char a[11];
    gets(a);
    if(strlen(a) < 6)
        continue;
    char b[10] = "CLOSEALL";
    if(!strcmp(a,b)){
        int j = 0;
        while(j<n+1)
           arr[j++] = 0;
        count = 0;
        printf("%d\n",count);
        l++;
        continue;
    }

    int t = 0;
    int i = 6;
    while(a[i] != '\0')
    {
        t = t*10 + (a[i] - 48);
        i++;
    }

    if(arr[t])
        count--;
    else
        count++;

    arr[t] = arr[t] == 0 ? 1 : 0;
    printf("%d\n",count);
    l++;
    }

    return 0;
}
