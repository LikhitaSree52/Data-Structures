#include<stdio.h>
struct node
{
        int data;
        struct node *link;
};
struct node* reverse_SLL(struct node *head);
void traverse_SLL(struct node *head);
int main()
{
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
        printf("Original SLL\n");
        traverse_SLL(head);
        printf("\nReversed SLL\n");
        head=reverse_SLL(head);
	    traverse_SLL(head);
	
}
struct node* reverse_SLL(struct node *head)
{
	struct node *temp1=NULL;
	struct node* temp2=NULL;
	while(head!=NULL)
	{
		temp2=head->link;
		head->link=temp1;
		temp1=head;
		head=temp2;
	}
	head=temp1;
	return head;
}
void traverse_SLL(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	if(head==NULL)
		printf("No node is attached");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("NULL");
}
