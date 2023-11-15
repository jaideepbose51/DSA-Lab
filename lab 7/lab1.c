#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL; // Define the top pointer globally

void push();
void pop();
void peak();
void display();

int main()
{
    int ch;
    while (1)
    {
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display\n");
        printf("Enter 5 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void push()
{
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        struct stack *temp = top;
        printf("Popped data: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peak()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        struct stack *current = top;
        printf("Stack contents: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
