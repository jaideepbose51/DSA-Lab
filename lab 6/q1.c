#include <stdio.h>
#include <stdbool.h>

int stack[10];
int top = -1;

// Function to push an element onto the stack
void push(int element)
{
    if (top >= 10 - 1)
    {
        printf("Stack is full. Cannot push %d.\n", element);
    }
    else
    {
        stack[++top] = element;
        printf("%d pushed onto the stack.\n", element);
    }
}

// Function to pop an element from the stack
int pop()
{
    if (top == -1)
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    else
    {
        int element = stack[top--];
        printf("%d popped from the stack.\n", element);
        return element;
    }
}

// Function to check if the stack is empty
bool isEmpty()
{
    return top == -1;
}

// Function to check if the stack is full
bool isFull()
{
    return top == 10 - 1;
}

// Function to display stack elements
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, element;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if the stack is empty\n");
        printf("4. Check if the stack is full\n");
        printf("5. Display stack elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            if (element != -1)
            {
                printf("%d popped from the stack.\n", element);
            }
            break;
        case 3:
            if (isEmpty())
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
            break;
        case 4:
            if (isFull())
            {
                printf("Stack is full.\n");
            }
            else
            {
                printf("Stack is not full.\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
