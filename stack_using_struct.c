#include <stdio.h>
#define MAX_SIZE 5

struct Stack
{
    int stack[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        return s->stack[s->top];
    }
}

int push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("The stack is full\n");
    }
    else
    {
        s->stack[++s->top] = value;
        return value;
    }
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else 
    {
        return s->stack[s->top--];
    }
}

void display_stack(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
       	{
            printf("%d ", s->stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    printf("Elements before pop operation:\n");
    display_stack(&s);
    printf("Peek value: %d\n", peek(&s));
    printf("Popped Element: %d\n", pop(&s));
    printf("Peek value: %d\n", peek(&s));
    printf("Popped Element: %d\n", pop(&s));
    printf("Popped Element: %d\n", pop(&s));
    printf("Peek value: %d\n", peek(&s));
    printf("Popped Element: %d\n", pop(&s));
    printf("Peek value: %d\n", peek(&s));
    printf("Elements after pop operation:\n");
    display_stack(&s);

    if(isEmpty(&s))
	    printf("The Stack is empty");
    else
	    printf("The stack is not empty");
}
