#include <stdio.h>
#include <stdlib.h>

struct node
{
    int eno;
    char name[100], dept[100], sal[10];
    struct node *next, *prev;
};

typedef struct node *NODE;

NODE start = NULL;
int size = 0;

NODE createNode()
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d %s %s %s", &newNode->eno, newNode->name, newNode->dept, newNode->sal);
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void insertAtEnd()
{
    NODE snode = createNode();
    if (start == NULL)
    {
        start = snode;
        size++;
        return;
    }

    NODE temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = snode;
    snode->prev = temp;
    size++;
}

void insertAtFront()
{
    NODE snode = createNode();
    if (start == NULL)
    {
        start = snode;
        size++;
        return;
    }

    snode->next = start;
    start->prev = snode;

    start = snode;
    size++;
}

void deleteAtFront()
{
    if (start == NULL)
    {
        printf("No element to Delete!\n");
        return;
    }
    NODE temp = start;
    if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        start = start->next;
        start->prev = NULL;
    }
    free(temp);
    size--;
}

void deleteAtEnd()
{
    if (start == NULL)
    {
        printf("No element to Delete!\n");
        return;
    }

    NODE temp = start;
    if (start->next == NULL)
        start = NULL;
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    free(temp);
    size--;
}

void display()
{
    printf("Number of elements are %d\n", size);

    if (size > 0)
    {
        printf("Elements are: ");
        NODE temp = start;
        while (temp != NULL)
        {
            printf("%s, ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("1. Insert at Front\n2. Insert at End\n3. Delete at Front\n4. Delete at End\n5. Display\n6. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtFront();
            break;

        case 2:
            insertAtEnd();
            break;

        case 3:
            deleteAtFront();
            break;

        case 4:
            deleteAtEnd();
            break;

        case 5:
            display();
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