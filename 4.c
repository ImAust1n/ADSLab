#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STACK_MAX_SIZE 20
char stack [STACK_MAX_SIZE];
int top = -1;

int isFull() {
	return top == STACK_MAX_SIZE;
}

int isEmpty() {
	return top == -1;
}

void push(int n) {
	stack[++top] = n;
}

char pop() {
	return stack[top--];
}

int precedence(char c) {
	if (c == '^') return 3;
	if (c == '*' || c == '/' || c == '%') return 2;
	if (c == '+' || c == '-') return 1;
	return 0;
}

void postfix(char s[]) {
	int n = strlen(s);
	char res[20]; int j = 0;
	
	for (int i = 0; i < n; i++) {
		if (isalnum(s[i])) {
			res[j++] = s[i];
		} else {
			if (s[i] == '(') {
				push(s[i]);
			} else if (!isEmpty() && s[i] == ')') {
				while (s[top] != '(') {
					res[j++] = pop();
					if (isEmpty()) {
						printf("Invalid\n");
						return;
					}
				}
				pop();
			} else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^' || s[i] == '%') {
				while (precedence(stack[top]) >= precedence(s[i])) {
					res[j++] = pop();
				}
				push(s[i]);
			} else {
				printf("Invalid!\n");
				return;
			}
		}
	}

	while (!isEmpty()) {
		if (stack[top] == '(') {
			printf("Invalid!");
			break;
		}
		res[j++] = pop();
	}
	res[j] = '\0';

	printf("PostFix: %s", res);
}

int main() {
	char exp[20];
	char *e, x;
	printf("Enter the expression : ");
	scanf("%s",exp);
	e = exp;
	postfix(e);
	return 0;
}