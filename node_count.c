#include<stdio.h>
struct node
{
        int data;
        struct node *link;
};
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
        traverse_SLL(head);
}
void traverse_SLL(struct node *head)
{
        struct node *temp=NULL;
        int count=0;
	temp=head;
        if(head==NULL)
                printf("No node is attached");
        while(temp!=NULL)
        {
                count++;
                temp=temp->link;
        }
	printf("Count:%d",count);
}

