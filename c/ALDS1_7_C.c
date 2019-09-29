#include <stdio.h>

typedef struct {
    int parent, left, right;
} Node;

#define MAX 100
#define NIL -1
Node T[MAX];

void preOrder(int u) {
    if (u == NIL) return;
    printf(" %d", u);
    preOrder(T[u].left);
    preOrder(T[u].right);
}

void inOrder(int u) {
    if (u == NIL) return;
    inOrder(T[u].left);
    printf(" %d", u);
    inOrder(T[u].right);
}

void postOrder(int u) {
    if (u == NIL) return;
    postOrder(T[u].left);
    postOrder(T[u].right);
    printf(" %d", u);
}


int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) T[i].parent = NIL;

    for (int i = 0; i < n; i++) {
        int v, l, r;
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
            break;
        }
    }

    printf("%s\n", "Preorder");
    preOrder(root);
    printf("\n");

    printf("%s\n", "Inorder");
    inOrder(root);
    printf("\n");

    printf("%s\n", "Postorder");
    postOrder(root);
    printf("\n");
    return 0;
}
