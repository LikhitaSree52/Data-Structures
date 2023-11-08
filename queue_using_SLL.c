#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*front=NULL,*rear=NULL;

int (isEmpty())
{
	return rear==NULL;
}

int enqueue(int data)
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->link=NULL;
	if(front==NULL)
	{
		front=rear=new;
	}
	rear->link=new;
	rear=new;
}

int dequeue()
{
	int a;
	a=front->data;
	struct node *temp=front;
	if(isEmpty())
	{
		printf("Queue is empty");
	}
	else
	{
		front=temp->link;
		free(temp);
	}
	return a;
	
}

int frontvalue()
{
	if(isEmpty())
	{
		printf("Queue is empty");
	}
	else
	{
		return front->data;
	}
}

int display()
{
	struct node *temp=front;
	if(isEmpty())
        {
                printf("Queue is empty");
        }
        while(temp!=NULL)
	{
		printf("%d \t",temp->data);
		temp=temp->link;
	}
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	printf("Elements before dequeue operation\n");
	display();
	printf("\nFront Value :%d \n",frontvalue());
	printf("Dequeued element :%d \n",dequeue());
	printf("\nElements after dequeue operation\n");
        display();
	printf("\nDequeued element :%d \n",dequeue());
	printf("\nElements after dequeue operation\n");
	display();
	printf("\nFront Value :%d \n",frontvalue());
	if(isEmpty())
	{
		printf("\nQueue is empty");
	
	}
	else
	{
		printf("Queue is not empty");
	}
}



