#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top;
void push(int x);
int pop();

int main(int argc, char const* argv[])
{
    char s[20];
    int a, b;
    while (scanf("%s", s) != EOF) {
        if (s[0] == '+') {
            b = pop();
            a = pop();
            push(a + b);
        } else if (s[0] == '-') {
            b = pop();
            a = pop();
            push(a - b);
        } else if (s[0] == '*') {
            b = pop();
            a = pop();
            push(a * b);
        } else {
            push(atoi(s));;
        }
    }

    printf("%d\n", pop());
;
    return 0;
}

void push(int x) {
    stack[top] = x;
    top++;
}

int pop(int x) {
    return stack[--top];
}
