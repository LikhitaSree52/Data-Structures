#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev_link;
    struct node* next_link;
};

void traverse_DLL(struct node* head);
struct node* insert_DLL_beg(struct node* head, int data);
void insert_DLL_end(struct node* head, int data);
void insert_DLL_random(struct node* head, int position, int data);

int main()
{
    int choice, data, position;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->prev_link = NULL;
    head->next_link = NULL;

    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = 20;
    current->prev_link = head;
    current->next_link = NULL;
    head->next_link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 30;
    current->prev_link = head->next_link;
    current->next_link = NULL;
    head->next_link->next_link=current;
    printf("Double Linked List is created.\n");

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
                printf("DLL before insertion at beginning\n");
                traverse_DLL(head);
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                printf("DLL after insertion at beginning\n");
                head = insert_DLL_beg(head, data);
                traverse_DLL(head);
                break;
            case 2:
                printf("DLL before insertion at end\n");
                traverse_DLL(head);
                printf("Enter the data to be inserted at the end: ");
                scanf("%d", &data);
                printf("DLL after insertion at end\n");
                insert_DLL_end(head, data);
                traverse_DLL(head);
                break;
            case 3:
                printf("DLL before insertion at random\n");
                traverse_DLL(head);
                printf("Enter the position where the node should be inserted: ");
                scanf("%d", &position);
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("DLL after insertion at random\n");
                insert_DLL_random(head, position, data);
                traverse_DLL(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void traverse_DLL(struct node* head)
{
    struct node* temp = head;
    if (head == NULL)
        printf("No nodes are attached\n");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next_link;
    }
    printf("NULL\n");
}

struct node* insert_DLL_beg(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->prev_link = NULL;
    new->next_link = head;
    head->prev_link = new;
    return new;
}

void insert_DLL_end(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->prev_link = NULL;
    new->next_link = NULL;
    struct node* temp = head;
    if (temp == NULL)
        printf("No nodes are attached\n");
    while (temp->next_link != NULL)
    {
        temp = temp->next_link;
    }
    temp->next_link = new;
    new->prev_link = temp;
}

void insert_DLL_random(struct node* head, int position, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->prev_link = NULL;
    new->next_link = NULL;
    struct node* temp = head;
    if (temp == NULL)
        printf("No nodes are attached\n");
    while (position>1)
    {
        temp = temp->next_link;
        position--;
    }
    new->next_link = temp->next_link;
    if (temp->next_link != NULL)
    {
        temp->next_link->prev_link = new;
    }
    temp->next_link = new;
    new->prev_link = temp;
}

