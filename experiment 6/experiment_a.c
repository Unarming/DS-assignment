// Design, Develop and Implement a Program in C for the following Stack Applications
// a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
// b. Solving Tower of Hanoi problem with n disks


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double compute(char symbol, double op1, double op2) {
    switch (symbol) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '$':
        case '^': return pow(op1, op2);
        default: return 0;
    }
}

int main() {
    double s[20], res, op1, op2;
    int top = -1, i;
    char postfix[20], symbol;

    printf("\nEnter the postfix expression:\n");
    fgets(postfix, sizeof(postfix), stdin);

    for (i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];

        if (isdigit(symbol)) {
            s[++top] = symbol - '0';
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '$') {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }

    res = s[top--];
    printf("\nThe result is : %f\n", res);

    return 0;
}