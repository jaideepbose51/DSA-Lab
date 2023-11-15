#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start;

void display();
void insert();
void deleteNode();
void count();

int main()
{
    struct node *temp;
    struct node *new;
    int n;
    start = NULL;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &n);
    if (n >= 1)
    {
        start = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &start->data);
        start->next = NULL;
        n--;
        temp = start;
        while (n != 0)
        {
            new = (struct node *)malloc(sizeof(struct node));
            printf("Enter Data: ");
            scanf("%d", &new->data);
            new->next = NULL;
            temp->next = new;
            temp = new;
            n--;
        }
        display();
    }
    else
    {
        printf("Enter a valid number of nodes\n");
    }

    while (1)
    {
        printf("\nMENU\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. COUNT\n");
        printf("4. TRAVERSE\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            count();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Choice\n");
            break;
        }
    }

    return 0;
}

void display()
{
    struct node *temp;
    temp = start;
    printf("Linked List Contents:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert()
{
    struct node *temp = start;
    if (start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &start->data);
        start->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &temp->next->data);
        temp->next->next = NULL;
    }
}

void deleteNode()
{
    int key;
    printf("Enter the data to delete: ");
    scanf("%d", &key);
    struct node *current = start;
    struct node *prev = NULL;

    if (current != NULL && current->data == key)
    {
        start = current->next;
        free(current);
        printf("Deleted %d from the list\n", key);
        return;
    }

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Data %d not found in the list\n", key);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Deleted %d from the list\n", key);
}

void count()
{
    struct node *temp;
    int i = 0;
    temp = start;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    printf("Number of records: %d\n", i);
}
