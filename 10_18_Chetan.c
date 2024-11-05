/* Program to convert Infix Expression to Postfix Expression */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char infix[50], postfix[50];
char stck[10];
int tos = -1;

void push(char);
char pop();
int priority(char);

void main() {
    int i = 0, j = 0;

    printf("Enter an infix Expression: ");
    fgets(infix, sizeof(infix), stdin);

    while (infix[i] != '\0' && infix[i] != '\n') {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (stck[tos] != '(') {
                postfix[j] = pop();
                j++;
            }
            tos--;
        }
        else {
            while (tos != -1 && priority(stck[tos]) >= priority(infix[i]) && stck[tos] != '(') {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
        i++;
    }
    while (tos != -1) {
        postfix[j] = pop();
        j++;
    }

    printf("\nPostfix expression is: %s\n", postfix);
}

void push(char x) {
    if (tos == 9) {
        printf("Stack is Full!\n");
        exit(1);
    }
    else {
        tos++;
        stck[tos] = x;
    }
}

char pop() {
    if (tos == -1) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    else {
        char y = stck[tos];
        tos--;
        return y;
    }
}

int priority(char z) {
    if (z == '*' || z == '/') {
        return 2;
    }
    else if (z == '+' || z == '-') {
        return 1;
    }
    return 0;
}

