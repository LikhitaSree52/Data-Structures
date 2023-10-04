#include<stdio.h>
struct node
{
        int data;
        struct node *link;
};
struct node* insert_SLL_beg(struct node *head,int data);
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
        head=insert_SLL_beg(head,0);
	traverse_SLL(head);
}
 struct node* insert_SLL_beg(struct node *head,int data)
{
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->link=NULL;

        //struct node *temp=(struct node *)malloc(sizeof(struct node));
	//{
		new->link=head;
		head=new;
	//}
	return head;
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

        
