#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idx;
    int amount;
} Pair;

#define MAX 20000

typedef struct {
    int top;
    int items[MAX];
} S1;

typedef struct {
    int top;
    Pair items[MAX];
} S2;

S1 s1;
S2 s2;

void S1_push(int x) {
    s1.items[s1.top++] = x;
}

int S1_top() {
    return s1.items[s1.top - 1];
}

void S1_pop() {
    s1.top--;
}

int S1_size() {
    return s1.top;
}

void S2_push(Pair x) {
    s2.items[s2.top++] = x;
}

Pair S2_top() {
    return s2.items[s2.top - 1];
}

void S2_pop() {
    s2.top--;
}

int S2_size() {
    return s2.top;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(int argc, char const* argv[])
{
    char ch;
    int sum = 0;
    for (int i = 0; scanf("%c", &ch) != EOF; i++) {
        if (ch == '\\') {
            S1_push(i);
        } else if (ch == '/' && S1_size() > 0) {
            int j = S1_top();
            S1_pop();
            sum += i - j;
            int a = i - j;
            while (S2_size() > 0 && S2_top().idx > j) {
                a += S2_top().amount;
                S2_pop();
            }
            Pair x = {j, a};
            S2_push(x);
        }
    }

    int ans[MAX];
    int nwater = S2_size();
    for (int i = 0; S2_size() > 0; i++) {
        ans[i] = S2_top().amount;
        S2_pop();
    }
    for (int i = 0; i < nwater / 2; i++) {
        swap(&ans[i], &ans[nwater-i-1]);
    }

    printf("%d\n", sum);
    printf("%d", nwater);
    for (int i = 0; i < nwater; i++) {
        printf(" %d", ans[i]);
    }
    printf("\n");

    return 0;
}
