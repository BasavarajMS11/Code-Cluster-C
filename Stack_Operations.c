#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack
{
	int data[MAX];
	int top;
};
typedef struct stack stack;

int full(stack s)
{
	if(s.top==MAX-1)
		return(1);
	else
		return(0);
}

int empty(stack s)
{
	if(s.top==-1)
		return(1);
	else
		return(0);
}

void PUSH(stack *ps,int num)
{
	if(full(*ps))
	{
		printf("\nStack Overflow!!");
		return;
	}
	ps->top++;
	ps->data[ps->top]=num;
	return;
}

int POP(stack *ps)
{
	int temp;

	if(empty(*ps))
	{
		printf("\nStack Underflow");
		return;
	}
	temp=ps->data[ps->top];
	ps->top--;
	return(temp);
}

void display(stack s)
{
	int i;
	if(empty(s))
	{
		printf("\nStack is empty");
		return;
	}
	for(i=0; i<=s.top; i++)
	{
		printf("%5d",s.data[i]);
	}
}


int main()
{
	stack s;
	int ch,done=1,num,x;

	s.top=-1;//Initially stack top points to -1

	while(1)
	{
		printf("\n1:PUSH \n2:POP \n3:DISPLAY \n4-EXIT");
		printf("\nEnter any option[1-4]");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter the element to be pushed");
                    scanf("%d",&num);
                    PUSH(&s,num);
                    break;
			case 2: x=POP(&s);
                    if(x!=-1)
                    {
                    printf("\n%d is poped",x);
                    }
                    break;
			case 3: display(s);
                    break;

			default :exit(0);
		}
	}
return 0;
}
