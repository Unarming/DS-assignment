// Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix Expression.
// Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /,
// % (Remainder), ^ (Power) and alphanumeric operands.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char x) {
    if (top >= SIZE - 1) {
        printf("\nStack Overflow.");
    } else {
        top = top + 1;
        stack[top] = x;
    }
}

char pop() {
    char item;
    if (top == -1) {
        printf("Stack Underflow: Invalid infix expression\n");
        getchar();
        exit(1);
    } else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return -1; 
}

int main() {
    char exp[20];
    char *e, x;

    printf("Enter the expression: ");
    scanf("%s", exp);
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (top != -1 && priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}