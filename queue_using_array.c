#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front=-1;
int rear=-1;

int isEmpty()
{
	return rear==-1;
}

int isFull()
{
	return rear==MAX_SIZE-1;
}

int frontvalue()
{
	if(isEmpty())
	{
		printf("Queue is empty\n");
	}
	else
	{
		return queue[front];
	}
}

int enqueue(int data)
{
	if(isFull())
	{
		printf("Queue is full\n");
	}
	else
	{
		return queue[rear++]=data;
	}
}

int dequeue()
{
	if(isEmpty())
	{
		printf("Queue is empty\n");
	}
	else
	{
		if(front==rear)
		{
			front=-1;
		}
		else
		{
			front++;
			return queue[front-1];
		}
	}
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=front;i<rear;i++)
		{
			printf("%d \t",queue[i]);
		}
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
	printf("Elements after dequeue operation\n");
        display();
	printf("\nDequeued element :%d \n",dequeue());
	printf("Elements after dequeue operation\n");
	display();
	printf("\nFront Value :%d \n",frontvalue()); 
}
