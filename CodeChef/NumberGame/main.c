#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d",&t);

    int i;
    int ld;
    getchar();
    for(i=0;i<t;i++)
    {
        while(1)
        {
            char ch = getchar();
            if(ch == '\n'){
                ld = ld - 48;
                if(ld % 2 == 0)
                {
                    printf("ALICE\n");
                }
                else
                {
                    printf("BOB\n");
                }
                break;
            }
            ld = ch;
        }
    }

    return 0;
}

