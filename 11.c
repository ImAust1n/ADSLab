#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

typedef struct node *BSTNODE;

BSTNODE createNode(int item)
{
    BSTNODE newNode = (BSTNODE)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    printf("Item created Successfully\n");
    return newNode;
}

void inorder(BSTNODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(BSTNODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BSTNODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

BSTNODE insert(BSTNODE root, int item)
{
    if (root == NULL)
    {
        return createNode(item);
    }

    if (root->data > item)
    {
        root->left = insert(root->left, item);
    }
    else if (root->data < item)
    {
        root->right = insert(root->right, item);
    }
    return root;
}

BSTNODE search(BSTNODE root, int item)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == item)
    {
        return root;
    }
    else if (root->data > item)
    {
        return search(root->left, item);
    }
    else
    {
        return search(root->right, item);
    }

    return NULL;
}

int main()
{
    int choice, item;
    BSTNODE root = NULL;

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            root = insert(root, item);
            break;

        case 2:
            printf("Enter item to search for: ");
            scanf("%d", &item);
            BSTNODE res = search(root, item);
            if (res != NULL)
                printf("Item Found!");
            else
                printf("Item not found!");
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 6:
            exit(0);

        default:
            printf("Enter correct choice!\n");
            break;
        }
    }

    return 0;
}