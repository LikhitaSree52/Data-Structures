#include<stdio.h>
struct node
{
        int data;
        struct node *link;
};
void traverse_SLL(struct node *head);
void delete_SLL_end(struct node *head);
int main()
{
	int data;
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

	delete_SLL_end(head);
	traverse_SLL(head);

}
void traverse_SLL(struct node *head)
{
        struct node *temp=head;
        if(head==NULL)
                printf("No node is attached");
        while(temp!=NULL)
        {
                printf("%d",temp->data);
                printf("\n");
                temp=temp->link;
        }
}
void delete_SLL_end(struct node *head)
{
	struct node *temp=head;
	if(temp==NULL)
		printf("No node is attached");
	else if(temp->link==NULL)
	{
		free(temp);
		head=NULL;
	}
	while(temp->link->link!=NULL)
	{
		temp=temp->link;
	}
	free(temp->link);
	temp->link=NULL;
}
