// Write a program to create a circular linked list and display the elements of the list.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a circular linked list
void insert(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode; // Point to itself since it's the only node
        *head = newNode;
    }
    else
    {
        struct Node *last = (*head)->next;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}

// Function to traverse and print the circular linked list
void traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    printf("Enter the number of nodes: ");
    int n, data;
    scanf("%d", &n);

    printf("Enter data for each node:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Circular Linked List: ");
    traverse(head);

    // Free allocated memory for nodes (not typically done for a circular linked list)
    struct Node *current = head;
    struct Node *temp;
    do
    {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

    return 0;
}