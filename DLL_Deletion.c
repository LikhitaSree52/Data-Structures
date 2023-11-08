#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev_link;
    struct node* next_link;
};

void traverse_DLL(struct node* head);
struct node* delete_DLL_beg(struct node* head);
void delete_DLL_end(struct node* head);
void delete_DLL_random(struct node* head, int position);

int main()
{
    int choice,position;
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
    head->next_link->next_link = current;
    printf("Double Linked List is created.\n");

    while (1)
    {
        printf("\nChoose an option\n");
	printf("1. Delete from the beginning\n");
        printf("2. Delete from the end\n");
        printf("3. Delete from a random position\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("DLL before deletion from the beginning\n");
                traverse_DLL(head);
                printf("DLL after deletion from the beginning\n");
                head = delete_DLL_beg(head);
                traverse_DLL(head);
                break;
            case 2:
                printf("DLL before deletion from the end\n");
                traverse_DLL(head);
                printf("DLL after deletion from the end\n");
                delete_DLL_end(head);
                traverse_DLL(head);
                break;
            case 3:
                printf("DLL before deletion from a random position\n");
                traverse_DLL(head);
                printf("Enter the position from which the node should be deleted: ");
                scanf("%d", &position);
                printf("DLL after deletion from a random position\n");
                delete_DLL_random(head, position);
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

struct node* delete_DLL_beg(struct node* head)
{
    if (head == NULL)
    {
        printf("The list is empty. Nothing to delete.\n");
        return head;
    }

    struct node* temp = head;
    head = head->next_link;
    if (head != NULL)
    {
        head->prev_link = NULL;
    }
    free(temp);
    return head;
}

void delete_DLL_end(struct node* head)
{
    if (head == NULL)
    {
        printf("The list is empty, nothing to delete.\n");
    }

    struct node* temp = head;
    while (temp->next_link != NULL)
    {
        temp = temp->next_link;
    }

    if (temp->prev_link != NULL)
    {
        temp->prev_link->next_link = NULL;
    }
    else
    {
	    head = NULL;
    }
    free(temp);
}

void delete_DLL_random(struct node* head, int position)
{
    if (head == NULL)
    {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    struct node* temp = head;

    if (position == 1)
    {
        head = temp->next_link;
        if (head != NULL)
        {
            head->prev_link = NULL;
        }
        free(temp);
	temp=NULL;
    }
    else
    {
        while (position > 1)
        {
            temp = temp->next_link;
            position--;
        }

        if (temp->prev_link != NULL)
        {
            temp->prev_link->next_link = temp->next_link;
        }

        if (temp->next_link != NULL)
        {
            temp->next_link->prev_link = temp->prev_link;
        }
        free(temp);
    }
}

