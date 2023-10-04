// Write a menu driven program to create a stack using linked list and perform the following operation using function
// a. Push
// b. Pop
// c. IsEmpty
// d. display the stack elements

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void push();
void pop();
void isempty();
void display(struct node *);

int main()
{
    int n;
    struct node *p;
    head = NULL;
    printf("Enter no of entries you want to make : ");
    scanf("%d", &n);
    if (n > 0)
    {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &p->data);
        p->next = NULL;
        n--;
        head = p;
        p = NULL;
        free(p);
        while (n > 0)
        {
            p = (struct node *)malloc(sizeof(struct node));
            printf("Enter data :");
            scanf("%d", &p->data);
            p->next = head;
            head = p;
            p = NULL;
            free(p);
            n--;
        }
    }
    else
    {
        printf("Not a valid input \n");
    }
    while (1)
    {
        printf("Enter 1 to Push\n");
        printf("Enter 2 to Pop\n");
        printf("Enter 3 to IsEmpty\n");
        printf("Enter 4 to display the stack elements\n");
        printf("Enter your choice :");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            isempty();
            break;

        case 4:
            display(head);
            break;

        default:
            break;
        }
    }
}

void push()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &p->data);
    p->next = head;
    head = p;
    p = NULL;
    free(p);
}

void pop()
{
    struct node *p;
    printf("%d", head->data);
    p = head;
    head = head->next;
    free(p);
}

void isempty()
{
    if (head == NULL)
    {
        printf("Stack is empty \n");
    }
    else
        printf("Stack is not empty \n");
}

void display(struct node *temp)
{
    if (temp == NULL)
        return;
    display(temp->next);
    printf("%d -> ", temp->data);
}