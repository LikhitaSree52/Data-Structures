#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

void traverse_SLL(struct node* head);
struct node* insert_SLL_beg(struct node* head, int data);
void insert_SLL_end(struct node* head, int data);
void insert_SLL_random(struct node* head, int position, int data);

int main()
{
    int choice, data, position;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;
    printf("Single Linked List is created.\n");

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
            printf("SLL before insertion at beginning\n");
            traverse_SLL(head);
            printf("Enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                printf("SLL after insertion at beginning\n");
                head = insert_SLL_beg(head, data);
                traverse_SLL(head);
                break;
            case 2:
                printf("SLL before insertion at end\n");
                traverse_SLL(head);
                printf("Enter the data to be inserted at the end: ");
                scanf("%d", &data);
                printf("SLL after insertion at end\n");
                insert_SLL_end(head, data);
                traverse_SLL(head);
                break;
            case 3:
                printf("SLL before insertion at random\n");
                traverse_SLL(head);              
                printf("Enter the position where the node should be inserted: ");
                scanf("%d", &position);
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("SLL after insertion at random\n");
                insert_SLL_random(head, position, data);
                traverse_SLL(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void traverse_SLL(struct node* head)
{
    struct node* temp = head;
    if (head == NULL)
        printf("No nodes are attached\n");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

struct node* insert_SLL_beg(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = head;
    head = new;
    return head;
}

void insert_SLL_end(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    struct node* temp = head;
    if (temp == NULL)
        printf("No nodes are attached\n");
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
}

void insert_SLL_random(struct node* head, int position, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    struct node* temp = head;
    if (temp == NULL)
        printf("No nodes are attached\n");
    while (position != 2)
    {
        temp = temp->link;
        position--;
    }
    new->link = temp->link;
    temp->link = new;
}

