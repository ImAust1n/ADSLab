#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct node
{
    char data[MAX];
    int front, rear, size;
};

typedef struct node cq;

void initialize(cq *q)
{
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}

int isFull(cq *q)
{
    return (q->size == MAX);
}

int isEmpty(cq *q)
{
    return (q->size == 0);
}

void insert(cq *q, char item)
{
    if (isFull(q))
    {
        printf("Queue Overflow!\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->size++;
    q->data[q->rear] = item;
    printf("Inserted element %c\n", item);
}

void delete(cq *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Removed Element %c\n", q->data[q->front]);
    q->front = (q->front + 1) % MAX;
    q->size--;
}

void display(cq *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return;
    }

    int count = q->size;
    int i = q->front;
    printf("Elements are: ");
    while (count--)
    {
        printf("%c, ", q->data[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    cq q;
    initialize(&q);
    int choice;
    char item;

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exitn\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf(" %c", &item);
            insert(&q, item);
            break;

        case 2:
            delete (&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Enter correct choice!\n");
        }
    }

    return 0;
}