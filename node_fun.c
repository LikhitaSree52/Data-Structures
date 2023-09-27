#include<stdio.h>
struct node
{
	int data1;
	char data2;
	struct node *link;
};
int main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data1=20;
	head->data2='D';
	head->link=NULL;
	printf("%d \t %c \t %d",head->data1,head->data2,head->link);
	struct node *current=(struct node*)malloc(sizeof(struct node));
	current->data1=30;
	current->data2='S';
	current->link=NULL;
	head->link=current;
	printf("\n %d \t %c",head->link->data1,head->link->data2);
	struct node *head1=(struct node*)malloc(sizeof(struct node));
        head1->data1=40;
        head1->data2='L';
        current->link=head1;
	printf("\n %d \t %c",current->link->data1,current->link->data2);


}
