#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
}*top=NULL;

int isEmpty()
{
	return top==NULL;
}

int push(int data)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->link=NULL;
	
	new->link=top;
	top=new;
	return top;
}

int pop()
{
	if (isEmpty())
	{
		printf("Stack is empty");
	}
	else
	{
		struct node *temp=top;
		top=temp->link;
		free(temp);
		temp=NULL;
		return top;
	}
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack is empty");
	}
	else
	{
		return top->data;
	}
}

void display()
{
	struct node *temp=top;
	if (isEmpty())
	{
		printf("Stack is empty");
	}
	while(temp)
	{
		printf("\n");
		printf("%d",temp->data);
		temp=temp->link;
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
	printf("Initial Stack value");
	display();
	printf("\nTop value : %d\n",peek());
	pop();
	pop();
	printf("\nStack after pop operation");
	display();
	if (isEmpty())
	{
		printf("\nStack is empty\n");
	}
	else 
	{
		printf("\nStack is not empty");
	}
}

