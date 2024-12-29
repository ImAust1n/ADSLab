#include <stdio.h>
#include <stdlib.h>

struct node
{
    int sno, sem;
    char name[50], branch[50];
    struct node *next;
};

typedef struct node *NODE;

NODE start = NULL;

NODE createNode()
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    printf("Enter details: ");
    scanf("%d %d %s %s", &newNode->sno, &newNode->sem, newNode->name, newNode->branch);
    newNode->next = NULL;
    return newNode;
}

void createAtFront()
{
    NODE snode = createNode();
    snode->next = start;
    start = snode;
}

void createAtEnd()
{
    NODE snode = createNode();
    if (start == NULL)
    {
        start = snode;
        return;
    }
    NODE temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = snode;
}

void deleteAtFront()
{
    if (start == NULL)
    {
        printf("No Node to Delete!\n");
        return;
    }

    NODE temp = start;
    start = start->next;
    free(temp);
}

void deleteAtEnd()
{
    if (start == NULL)
    {
        printf("No Node to Delete!\n");
        return;
    }

    if (start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        NODE temp = start->next;
        NODE prev = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void display()
{
    if (start == NULL)
    {
        printf("There is no Node to display.\n");
    }
    else
    {
        NODE temp = start;
        printf("Students are: ");
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
        printf("1. Create at Front\n2. Create at End\n3. Delete at Front\n4. Delete at End\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAtFront();
            break;
        case 2:
            createAtEnd();
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