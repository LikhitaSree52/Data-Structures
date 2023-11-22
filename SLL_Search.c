#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void search_sll(struct node *head, int data);
void traverse_sll(struct node *head);

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->link = NULL;

	struct node *current = (struct node*)malloc(sizeof(struct node));
	current->data = 20;
	current->link = NULL;
	head->link = current;

	current = (struct node*)malloc(sizeof(struct node));
	current->data = 30;
	current->link = NULL;
	head->link->link = current;

	traverse_sll(head);

	int searchData;
	printf("Enter the element to search: ");
	scanf("%d", &searchData);

	search_sll(head, searchData);

	return 0;
}

void traverse_sll(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("%d->", temp->data);
		temp = temp->link;
	}
	printf("NULL\n");
}

void search_sll(struct node *head, int data)
{
	struct node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			printf("Element %d is found\n", data);
			return;
		}
		else
			temp = temp->link;
	}
	printf("Element %d is not found\n", data);
}

