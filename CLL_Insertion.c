#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

void traverse_CLL(struct node* head);
struct node* insert_CLL_beg(struct node* head, int data);
struct node* insert_CLL_end(struct node* head, int data);
struct node* insert_CLL_random(struct node* head, int position, int data);

int main()
{
    int choice, data, position;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->link = head;

    printf("\nCircular Linked List is created.\n");

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a random position\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("CLL before insertion at beginning\n");
                traverse_CLL(head);
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d",&data);
                printf("CLL after insertion at beginning\n");
                head = insert_CLL_beg(head, data);
                traverse_CLL(head);
                break;
            case 2:
                printf("CLL before insertion at end\n");
                traverse_CLL(head);
                printf("Enter the data to be inserted at the end: ");
                scanf("%d",&data);
                printf("CLL after insertion at end\n");
                head = insert_CLL_end(head, data);
                traverse_CLL(head);
                break;
            case 3:
                printf("CLL before insertion at random\n");
                traverse_CLL(head);
                printf("Enter the position where the node should be inserted: ");
                scanf("%d",&position);
                printf("Enter the data for the new node: ");
                scanf("%d",&data);
                printf("CLL after insertion at random\n");
                head = insert_CLL_random(head, position, data);
                traverse_CLL(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void traverse_CLL(struct node* head)
{
    struct node* temp = head->link;
    if (head == NULL)
        printf("No nodes are attached\n");
    else
    {
        do
        {
            printf("%d->", temp->data);
            temp = temp->link;
        } while (temp != head->link);
	printf("%d //Circular Linked list last node connected to first %d\n", head->data,head->data);
    }
}

struct node* insert_CLL_beg(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = head->link;
    head->link = new;
  
    return head;
}

struct node* insert_CLL_end(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = head->link;
    head->link = new;
    head = head->link;
  
    return head;
}

struct node* insert_CLL_random(struct node* head, int position, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;

    struct node* temp = head->link;
    if (position == 0)
    {
        new->link = head->link;
        head->link = new;
 
        return head;
    }
    else 
    {
        while (position > 1)
        {
            temp = temp->link;
            position--;
        }
        new->link = temp->link;
        temp->link = new;
        if (temp == head)
        {
            head = head->link;
        }
        return head;
    }
}

