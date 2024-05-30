#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node stack;

stack *top=NULL;
void push(int e)
{
	stack *t = (stack *)malloc(sizeof(stack));
	t->data=e;
	t->next=top;
	top=t;
}

void pop()
{
	if(top==NULL)
		printf("Stack Underflow\n");
	else
	{
		printf("%d\n",top->data);
		top = top->next;
	}
}

void peek()
{
	if(top==NULL)
		printf("Empty Stack\n");
	else
		printf("%d\n",top->data);
}


int menu()
{
    int ch;
    printf("\nPush - 1\nPop - 2\nPeek - 3\nExit - 4\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

void main()
{
    int i,ch,a;
    for(ch = menu();ch != 4;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter an element to insert : ");
            		 scanf("%d",&a);
					 push(a);
                     break;
            case 2 : pop();
                     break;
            case 3 : peek();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
}
