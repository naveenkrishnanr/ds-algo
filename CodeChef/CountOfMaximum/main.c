#include <stdio.h>

typedef struct maxCombo maxCombo;

struct maxCombo{
    short int num;
    short int count;
}maxDefault={0,0};


int main(void)
{

    int t;
    scanf("%d",&t);

    while(t>0){
        int n;
        scanf("%d",&n);
        short int a[10001]={};
        maxCombo max = maxDefault;
        short int temp;
        while(n>0){

            scanf("%hd",&temp);

            a[temp]++;
            if(a[temp] > max.count){
                max.num = temp;
                max.count = a[temp];
            }
            else if(a[temp] == max.count){
                if(max.num > temp){
                    max.num = temp;
                    max.count = a[temp];
                }
            }
            n--;
        }

        printf("%d %d\n",max.num,max.count);
        t--;
    }

    return 0;
}

