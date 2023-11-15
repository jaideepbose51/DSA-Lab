#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the queue
struct Node
{
    int data;
    struct Node *next;
};

// Structure for the queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Structure for stack using a single queue
struct Stack
{
    struct Queue *queue;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}

// Function to enqueue an item to the queue
void enqueue(struct Queue *queue, int item)
{
    struct Node *newNode = createNode(item);

    // If the queue is empty, set both front and rear to the new node
    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
        return;
    }

    // Otherwise, add the new node to the rear
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an item from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;

    // Remove the front node and update front
    struct Node *temp = queue->front;
    int item = temp->data;
    queue->front = temp->next;

    // If front becomes NULL, update rear to NULL as well
    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return item;
}

// Function to initialize a stack
struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->queue = createQueue();
    return stack;
}

// Function to push an item onto the stack
void push(struct Stack *stack, int item)
{
    // Enqueue the new element to the queue
    enqueue(stack->queue, item);
}

// Function to pop an item from the stack
int pop(struct Stack *stack)
{
    // If the queue is empty, the stack is empty
    if (isEmpty(stack->queue))
        return -1;

    // Dequeue all elements except the last one and enqueue them again
    int size = queueSize(stack->queue);
    for (int i = 0; i < size - 1; i++)
    {
        int temp = dequeue(stack->queue);
        enqueue(stack->queue, temp);
    }

    // The last element is the one to be popped
    return dequeue(stack->queue);
}

// Function to get the size of the queue
int queueSize(struct Queue *queue)
{
    int size = 0;
    struct Node *temp = queue->front;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

// Function to display the menu
void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Quit\n");
}

// Driver program
int main()
{
    int choice, item;
    struct Stack *stack = createStack();

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &item);
            push(stack, item);
            break;
        case 2:
            printf("Popped element: %d\n", pop(stack));
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
