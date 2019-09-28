#include <stdio.h>
#include <stdlib.h>

#define MAX 100005
#define NIL -1

typedef struct {
    int p, l, r;
} Node;

Node T[MAX];
int D[MAX];

void print(int u) {
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].p);
    printf("depth = %d, ", D[u]);

    if (T[u].p == NIL)
        printf("root, ");
    else if (T[u].l == NIL)
        printf("leaf, ");
    else
        printf("internal node, ");

    printf("[");

    for (int i = 0, c = T[u].l; c!= NIL; i++, c = T[c].r) {
        if (i) printf(", ");
        printf("%d", c);
    }
    printf("]\n");
}

int rec(int u, int p) {
    D[u] = p;
    if (T[u].r != NIL) rec(T[u].r, p);
    if (T[u].l != NIL) rec(T[u].l, p+1);
}

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;

    for (int i = 0; i < n; i++) {
        int v, d;
        scanf("%d %d", &v, &d);
        int l = -1;
        for (int j = 0; j < d; j++) {
            int c; // v の子供
            scanf("%d", &c);
            if (j == 0) {
                T[v].l = c;
            } else {
                T[l].r = c;
            }
            l = c;
            T[c].p = v;
        }
    }

    // root node
    int r;
    for (int i = 0; i < n; i++) {
        if (T[i].p == NIL) {
            r = i;
            break;
        }
    }

    rec(r, 0);

    for (int i = 0; i < n; i++) {
        print(i);
    }

    return 0;
}
