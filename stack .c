#include <stdio.h>
#include <stdlib.h> 

#define NIL -1
#define MAX  10

typedef struct Stacktype{
    int a[MAX];
    int top;
} Stack;

int isfull(Stack);
int isempty(Stack);
void push(Stack *, int);
int pop(Stack *);

int main()
{
     int c, val, v;
     Stack s;
     s.top = NIL;
     
    while(1)
    {
        printf("\n1. push\n");
        printf("2. pop\n");
        printf("3. exit\n");
        printf("enter your choice : ");
        scanf("%d", &c);
        switch(c){
            case 1:
                if(isfull(s)){
                    printf("stack is full\n");
                    break;
                }
                else{
                    printf("enter value : ");
                    scanf("%d", &val);
                    push(&s, val);
                }
                break;
            case 2:
                if(isempty(s)){
                    printf("stack is empty\n");
                    break;
                }
                else{
                    v = pop(&s);
                    printf("Popped value: %d\n", v);
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("incorrect choice\n");
        }
    }
    return 0;
}

int isfull(Stack s)
{
    if(s.top==(MAX-1))
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(Stack s)
{
   if(s.top==NIL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(Stack *p, int val)
{
    p->top = p->top + 1;
    p->a[p->top] = val;
    
}

int pop(Stack *p)
{
    int v;
    v = p->a[p->top];
    p->top = p->top - 1;
    return v;
}


