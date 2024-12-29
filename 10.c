#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, exp;
    struct node *next;
};

typedef struct node *NODE;

NODE createNode(NODE tail, int coef, int pow)
{
    NODE snode = (NODE)malloc(sizeof(struct node));
    snode->coeff = coef;
    snode->exp = pow;

    if (tail == NULL)
    {
        snode->next = snode;
        return snode;
    }
    snode->next = tail->next;
    tail->next = snode;
    tail = snode;
    return tail;
}

NODE inputPoly(int n)
{
    int coeff, pow;
    scanf("%d %d", &coeff, &pow);
    NODE tail = NULL;
    tail = createNode(tail, coeff, pow);
    NODE head = tail;

    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &coeff, &pow);
        tail = createNode(tail, coeff, pow);
    }

    return head;
}

void displayPoly(NODE head)
{
    printf("%dx^%d", head->coeff, head->exp);
    NODE temp = head->next;
    while (temp != head)
    {
        printf(", %dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

NODE addPoly(NODE a, NODE b)
{
    NODE head1 = a;
    NODE head2 = b;
    NODE temp1 = head1->next;
    NODE temp2 = head2->next;

    NODE resHead = NULL;
    NODE resTail = NULL;

    resTail = createNode(resTail, head1->coeff + head2->coeff, head1->exp);
    resHead = resTail;

    while (temp1 != head1 && temp2 != head2)
    {
        if (temp1->exp == temp2->exp)
        {
            resTail = createNode(resTail, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            if (temp1->exp > temp2->exp)
            {
                resTail = createNode(resTail, temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            }
            else
            {
                resTail = createNode(resTail, temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            }
        }
    }

    while (temp1 != head1)
    {
        resTail = createNode(resTail, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != head2)
    {
        resTail = createNode(resTail, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return resHead;
}

int main()
{
    NODE head1 = NULL;
    NODE head2 = NULL;

    int n1, n2;
    scanf("%d", &n1);
    head1 = inputPoly(n1);

    scanf("%d", &n2);
    head2 = inputPoly(n2);

    displayPoly(head1);
    displayPoly(head2);

    NODE resHead = addPoly(head1, head2);
    displayPoly(resHead);
}