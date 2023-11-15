// Write a program to create a double linked list and perform the following menu based operations on it:
// i. insert an element at specific position
// ii. delete an element from specific position (ye nahi karna tha)
// iii. Traverse the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *pre;
    int data;
    struct node *next;
} *head;

void insert();
void display();

int main()
{
    head = NULL;
    struct node *p;
    struct node *q;
    int n;
    printf("Enter no of entries you want to make :");
    scanf("%d", &n);
    p = (struct node *)malloc(sizeof(struct node));
    p->pre = NULL;
    printf("Enter data :");
    scanf("%d", &p->data);
    p->next = NULL;
    head = p;
    n--;
    while (n > 0)
    {
        q = (struct node *)malloc(sizeof(struct node));
        p->next = q;
        q->pre = p;
        printf("Enter data :");
        scanf("%d", &q->data);
        q->next = NULL;
        p = q;
        n--;
        q = NULL;
        free(q);
    }
    p = NULL;
    free(p);
    while (1)
    {
        printf("Enter 1 to insert \n");
        printf("Enter 2 to traverse \n");
        printf("Enter your choice :");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}

void insert()
{
    struct node *temp;
    struct node *p, *q;
    int n;
    temp = head;
    printf("Enter index after which you want to insert the node :");
    scanf("%d", &n);
    if (n == 0)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->pre = NULL;
        printf("Enter Data :");
        scanf("%d", &p->data);
        p->next = head;
        head->pre = p;
        head = p;
    }
    else
    {
        while ((n - 1) > 0)
        {
            if (temp->next == NULL)
            {
                printf("Out of bound\n");
                return;
            }
            else
                temp = temp->next;
            n--;
        }
        q = temp->next;
        p = (struct node *)malloc(sizeof(struct node));
        p->pre = temp;
        printf("Enter Data :");
        scanf("%d", &p->data);
        p->next = q;
        temp->next = p;
        p = NULL;
        q = NULL;
        free(p);
        free(q);
    }
}

void display()
{
    struct node *temp;
    temp = head;
    do
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    } while (temp != NULL);
    temp = NULL;
    free(temp);
    return;
}
