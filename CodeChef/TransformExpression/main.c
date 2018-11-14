#include <stdio.h>

char queue[402];
int front = -1;
int back = -1;

char stack[402];
int top=-1;

void push(char a)
{
//    printf("pushing %c %d\n",a,top);
    stack[++top] = a;
}
char pop()
{
//    printf("poping %c %d\n",stack[top],top);
    return stack[top--];
}

void enque(char a)
{
    //    printf("pushing %c %d %d\n",a,front,back);
    if(back == 402)
        back = -1;
    queue[++back] = a;
}
char deque()
{
    //    printf("popping %c %d %d\n",queue[front],front,back);
    if(front == 402)
        front = 0;
    if(front == -1)
        front = 0;
    return queue[front++];
}
void scopeEnd()
{
    char p='0';
    while((p != '{' && p != '(') && front<=back)
    {
        p = deque();
        if(p != '(' && p != ')' && p != '{' && p != '}')
            printf("%c",p);
    }
    char x='0';
    while(top>=0 && ((x != '{' && x != '(')))
    {
        x = pop();
        if(x != '(' && x != ')' && x != '{' && x != '}')
            printf("%c",x);
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();

    int i;
    for(i = 0;i < n;i++)
    {
        char ch;
        front=-1;
        back=-1;
        top=-1;
        int br = 0;
        while(1)
        {
            ch = getchar();
            if(ch == '\n' || ch == '\r')
                break;

            if(ch == '(' || ch == '{'){
//                enque(ch);
                br++;
                push(ch);
            }
            else if(ch == ')')
            {
                br--;
                scopeEnd();
            }
            else if(ch == '}')
            {
                br--;
                scopeEnd();
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
                push(ch);
            else
            {
                if(front==back)
                {
                    enque(ch);
                }
                else{
                    enque(ch);
                    if(br==0)
                        scopeEnd();
                }
            }
        }
        printf("\n");
    }

    return 0;
}

