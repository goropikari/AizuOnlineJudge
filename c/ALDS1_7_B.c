#include <stdio.h>
#define MAX 10000
#define NIL -1

typedef struct {
    int parent, left, right;
} Node;

Node T[MAX];
int D[MAX], H[MAX];

void setDepth(int u, int d) {
    if (u == NIL) return;
    D[u] = d;
    setDepth(T[u].left, d+1);
    setDepth(T[u].right, d+1);
}

int setHeight(int u) {
    int h1, h2;
    h1 = h2 = 0;
    if (T[u].left != NIL) {
        h1 = setHeight(T[u].left) + 1;
    }
    if (T[u].right != NIL) {
        h2 = setHeight(T[u].right) + 1;
    }
    return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u) {
    int p = T[u].parent;
    if (p == NIL) return NIL;
    if (T[p].left != u && T[p].left != NIL)
        return T[p].left;
    if (T[p].right != u && T[p].right != NIL)
        return T[p].right;
    return NIL;
}

void print(int u) {
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].parent);
    printf("sibling = %d, ", getSibling(u));
    int deg = 0;
    if (T[u].left != NIL) deg++;
    if (T[u].right != NIL) deg++;
    printf("degree = %d, ", deg);
    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);

    if (T[u].parent == NIL) {
        printf("root\n");
    } else if (T[u].left == NIL && T[u].right == NIL) {
        printf("leaf\n");
    } else {
        printf("internal node\n");
    }
}


int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) T[i].parent = NIL;

    int v, l, r;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v, &l, &r);
        T[v].left = l;
        T[v].right = r;
        if (l != NIL) T[l].parent = v;
        if (r != NIL) T[r].parent = v;
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (T[i].parent == NIL) {
            root = i;
        }
    }

    setDepth(root, 0);
    setHeight(root);

    for (int i = 0; i < n; i++) print(i);

    return 0;
}
