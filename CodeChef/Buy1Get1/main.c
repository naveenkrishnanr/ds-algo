#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d",&t);
    char str[201];
    while(t>0){

        int a[55]={};
        int cost = 0;
        scanf("%s",str);
        int i=0;
        while(str[i]){
            char ch = str[i];
//            if(ch=='\n'){
//                break;
//            }
            cost++;
            if(ch>=65&&ch<=90){
                if(a[ch-65] == 1){
                    cost--;
                    a[ch-65]=0;
                }
                else
                    a[ch-65]=1;

            }
            else{
                if(a[ch-97+27] == 1){
                    cost--;
                    a[ch-97+27]=0;
                }
                else
                    a[ch-97+27]=1;
            }
            i++;
        }
        printf("%d\n",cost);
        t--;
    }
    return 0;
}

