#include<stdio.h>
struct node
{
        struct node* prev_link;
        int data;
        struct node* next_link;
};
void display(struct node* head);
int main()
{
        struct node* head=(struct node*)malloc(sizeof(struct node));
        head->prev_link=NULL;
        head->data=10;
        head->next_link=NULL;
        struct node* current=(struct node*)malloc(sizeof(struct node));
        current->prev_link=NULL;
        current->data=20;
        current->next_link=NULL;
        head->next_link=current;
        current->prev_link=head;
        display(head);
}
void display(struct node* head)
{
        struct node* temp=head;
        if(head==NULL)
                printf("List is empty");
        else
        {
                while(temp!=NULL)
                {
                        printf("%d->",temp->data);
                        temp=temp->next_link;
                }
		printf("NULL");
	}
}
