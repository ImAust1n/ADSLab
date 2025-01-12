#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 20

int stack[MAX], top = -1;

int isFull() {
    return top == MAX;
}

int isEmpty() {
    return top == -1;
}

void push(int n) {
    stack[++top] = n;
}

int pop() {
    return stack[top--];
}

void postfix(char s[]) {
    int n = strlen(s), a, b;

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            push(s[i] - '0');
        } else {
            if (isEmpty()) {
                printf("Invalid!\n");
                return;
            } else {
                b = pop();
                if (isEmpty()) {
                    printf("Invalid!\n");
                    return;
                }
                a = pop();

                switch (s[i]) {
                    case '+':
                        push(a + b);
                        break;
                    
                    case '-':
                        push(a - b);
                        break;
                    
                    case '/':
                        push(a / b);
                        break;

                    case '*':
                        push(a * b);
                        break;

                    case '%':
                        push(a % b);
                        break;

                    case '^':
                        push(pow(a, b));
                        break;

                    default:
                        printf("Invalid!\n");
                        return;
                }
            }
        }
    }

    int res = pop();
    if (!isEmpty()) {
        printf("Invalid!\n");
        return;
    }
    printf("Result: %d", res);
}

int main() {
    char str[20];
    scanf(" %s", str);
    postfix(str);
    return 0;
}