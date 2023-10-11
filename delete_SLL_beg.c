#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *link;
};
void traverse_SLL(struct node *head);
struct node* delete_SLL_beg(struct node *head);
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

	head = delete_SLL_beg(head);
	traverse_SLL(head);

}

void traverse_SLL(struct node *head)
{
        struct node *temp=head;
        if(head==NULL)
                printf("No node is attached");
        while(temp!=NULL)
        {
                printf("%d->",temp->data);
		temp=temp->link;
        }
	printf("NULL");
}

struct node*  delete_SLL_beg(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
	    printf("No node is attached");
    head= temp->link;
    free(temp);
    temp=NULL;
    return head;
}

