#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push %d.\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->array[stack->top--];
}

int reverseNumber(int num)
{
    struct Stack *stack = createStack(10);

    while (num != 0)
    {
        int digit = num % 10;
        push(stack, digit);
        num /= 10;
    }

    int reversed = 0;
    int multiplier = 1;

    while (!isEmpty(stack))
    {
        int digit = pop(stack);
        reversed += digit * multiplier;
        multiplier *= 10;
    }

    free(stack->array);
    free(stack);
    return reversed;
}

int main()
{
    int num;
    printf("Enter a number to reverse: ");
    scanf("%d", &num);

    int reversed = reverseNumber(num);

    printf("Reversed number: %d\n", reversed);

    return 0;
}
