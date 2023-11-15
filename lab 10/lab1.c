// Write a program to create a binary search tree of n data elements using linked list and perform the following menu driven operations:
// i. preorder traversal
// ii. postorder traversal
// iii. inorder traversal
// iv. search an element

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
} *root;

void insert();
void inorderTraversal(struct node *root);
void preorderTraversal(struct node *root);
void postorderTraversal(struct node *root);

int main()
{
    int ch;
    insert();
    while (1)
    {
        printf("Enter 1. to insert\n");
        printf("Enter 2. to display inorder\n");
        printf("Enter 3. to display preorder\n");
        printf("Enter 4. to display postorder\n");
        printf("Enter 5. to exit\n");
        printf("Enter your choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            free(root);
            root = NULL;
            insert();
            break;
        case 2:
            inorderTraversal(root);
            break;
        case 3:
            preorderTraversal(root);
            break;
        case 4:
            postorderTraversal(root);
            break;
        case 5:
            free(root);
            root = NULL;
            exit(0);
        }
    }
    inorderTraversal(root);
}

void insert()
{
    int n;
    int val;
    printf("Enter no of entries you want to make : ");
    scanf("%d", &n);
    while (n > 0)
    {
        printf("Enter data : ");
        scanf("%d", &val);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL)
        {
            // If the tree is empty, make the new node the root
            root = newNode;
        }
        else
        {
            struct node *temp = root;
            while (1)
            {
                if (val <= temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
        n--;
    }
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        printf("%d", root->data);
    }
}