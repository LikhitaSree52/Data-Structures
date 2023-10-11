#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *link;
};
void traverse_SLL(struct node *head);
void delete_SLL_random(struct node *head,int position);

int main()
{
	//int position;
        struct node *head=(struct node*)malloc(sizeof(struct node));
        head->data=10;
        head->link=NULL;

        struct node *current=(struct node*)malloc(sizeof(struct node));
        current->data=20;
        current->link=NULL;
        head->link=current;

        current=(struct node*)malloc(sizeof(struct node));
        current->data=30;
        current->link=NULL;
        head->link->link=current;

	//printf("Enter the node data value :");
	//scanf("%d",&data);

	//printf("Enter the position where the node to be inserted:");
	//scanf("%d",&position);
	delete_SLL_random(head,3);
	traverse_SLL(head);
}

void traverse_SLL(struct node *head)
{
        struct node *temp=head;
        if(head==NULL)
                printf("No node is attached");
        while(temp!=NULL)
        {
                printf("%d->", temp->data);
		temp=temp->link;
        }
	printf("NULL");
}

void delete_SLL_random(struct node* head,int position)
{
	struct node *temp=head;
	struct node *new=head;

	if(head==NULL)
		printf("No node is attached");
	
	else if(position==1)
	{
		head=temp->link;
		free(temp);
		temp=NULL;
	}
	while(position!=1)
	{
		new=temp;
		temp=temp->link;
		position--;
	}
	new->link=temp->link;
	free(temp);
	temp=new;
}
