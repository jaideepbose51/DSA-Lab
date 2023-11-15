#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Structure for queue using a single stack
struct Queue
{
    struct Stack *stack;
};

// Function to create a new stack
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

// Function to push an item to the stack
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to create a new queue
struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->stack = createStack(capacity);
    return queue;
}

// Function to enqueue an item to the queue
void enqueue(struct Queue *queue, int item)
{
    // Push the new item to the stack
    push(queue->stack, item);
}

// Function to dequeue an item from the queue
int dequeue(struct Queue *queue)
{
    // If the stack is empty, the queue is empty
    if (isEmpty(queue->stack))
    {
        printf("Queue is empty\n");
        return -1;
    }

    // Pop all items from the stack and push them back
    // to reverse the order of elements
    int item = pop(queue->stack);

    if (!isEmpty(queue->stack))
    {
        int frontItem = dequeue(queue);
        push(queue->stack, item);
        return frontItem;
    }

    return item;
}

// Function to display the menu
void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Quit\n");
}

// Driver program
int main()
{
    int choice, item;
    struct Queue *queue = createQueue(100);

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(queue));
            break;
        case 3:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
