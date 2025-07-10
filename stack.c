#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char item) {
    if(top == MAX-1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}
char pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default: 
        return 0;
    }
}
void infixToPostfix(char infix[], char postfix[]) {
    int i =0, j = 0;
    char ch, x;
    push('(');
    strcat(infix, ")");
    for(i=0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if(isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((x=pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression");
    return 0;
}
