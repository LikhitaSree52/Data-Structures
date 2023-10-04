#include<stdio.h>
struct node
{
        int data;
        struct node *link;
};
void traverse_SLL(struct node *head);
void insert_SLL(struct node *head,int data);
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

	printf("Enter the last node data value :");
	scanf("%d",&data);
	insert_SLL(head,data);
	traverse_SLL(head);

}
void insert_SLL(struct node *head,int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->link=NULL;

	struct node *temp=NULL;
		temp=head;
        if(temp==NULL)
		printf("No node is attached");
        while(temp->link!=NULL)
        {
		temp=temp->link;
	}
	temp->link=new;
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

