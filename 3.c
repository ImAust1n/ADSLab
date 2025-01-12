#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int data[5];
    int top;
};

typedef struct stack stk;

void initialize(stk *s) {
    s->top = -1;
}

int isFull(stk *s) {
    return (s->top == 5);
}

int isEmpty(stk *s) {
    return (s->top == -1);
}

void push(stk *s) {
    if (isFull(s)) {
        printf("Overflow!");
    } else {
        printf("Enter data: ");
        scanf("%d", &s->data[++s->top]);
    }
}

void pop(stk *s) {
    if (isEmpty(s)) {
        printf("Underflow!");
    } else {
        s->top--;
    }
}

void display(stk *s) {
    if (isEmpty(s)) {
        printf("Underflow!");
    } else {
        printf("Elements are: ");
        for (int i = s->top; i > 0; i--) {
            printf("%d, ", s->data[i]);
        }
        printf("\n");
    }
}

void checkPal(char s[]) {
    int flag = 1;
    int n = strlen(s);

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) flag = 0;
    }

    (flag) ? printf("Palindrome!") : printf("Not Palindrome!");
}

int main() {
    stk stack;
    initialize(&stack);

    int choice, value;
    char str[5];

    while (1) {
        printf("Menu:\n");
        printf("1. Push an element onto stack\n");
        printf("2. Pop an element from stack\n");
        printf("3. Check if a string is a palindrome\n");
        printf("4. Display stack status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&stack);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                printf("Enter a string to check palindrome: ");
                scanf("%s", str);
                checkPal(str);
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}