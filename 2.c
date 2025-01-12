#include <stdio.h>
#define MAX_CUST 20
#include <stdlib.h>

struct data {
    int ano;
    char name[50];
    float bal;
};

typedef struct data CUSTOMER;

void printLowBal(CUSTOMER c[], int count) {
    printf("Low Balance Customer are: ");
    for (int i = 0; i < count; i++) {
        if (c[i].bal < 200) {
            printf("%d, ", c[i].ano);
        }
    }
    printf("\n");
}

void increaseHighBal(CUSTOMER c[], int count) {
    printf("High Balance Customer are: ");
    for (int i = 0; i < count; i++) {
        if (c[i].bal > 1000) {
            c[i].bal += 200;
            printf("%d, ", c[i].ano);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of customers");
    scanf("%d", &n);

    CUSTOMER c[MAX_CUST];

    printf("Enter data: ");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &c[i].ano, c[i].name, &c[i].bal);
    }

    printLowBal(c, n);
    increaseHighBal(c, n);
}