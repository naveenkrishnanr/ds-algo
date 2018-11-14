#include <stdio.h>

typedef struct val{
    int number;
    int count;
}val;

void sort(val *b)
{
    int i,j;
    for(i=0;i<10;i++)
        for(j=i;j<9;j++)
            if(b[j].count > b[j+1].count)
            {
                val temp = b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t>0){


        val a[10];
        int i=0;
        for(i=0;i<10;i++){
            int temp;
            scanf("%d",&temp);

            a[temp].count = temp;
            a[temp].number = i;

        }

        sort(a);


        for(i=0;i<10;i++){

            printf("%d ",a[i].number);

        }

        t--;
    }

    return 0;
}

