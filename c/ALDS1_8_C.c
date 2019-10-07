#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int key;
    struct Node *right, *left, *parent;
};
typedef struct Node Node;

Node *root, *NIL;

Node * treeMinimum(Node *x) {
    while (x->left != NIL) x = x->left;
    return x;
}

Node * find(Node *u, int k) {
    while (u != NIL && k != u->key) {
        if (k < u->key) u = u->left;
        else u = u->right;
    }
    return u;
}

Node * treeSuccessor(Node *x) {
    if (x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;
    while (y != NIL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(Node *z) {
    Node *y;
    Node *x;

    if (z->left == NIL || z->right == NIL) y = z;
    else y = treeSuccessor(z); // left に子はいない

    if (y->left != NIL) {
        x = y->left;
    } else {
        x = y->right;
    }

    if (x != NIL) {
        x->parent = y->parent;
    }

    if (y->parent == NIL) {
        root = x;
    } else {
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }

    if (y != z)
        z->key = y->key;

    free(y);
}

void insert(int k) {
    Node *y = NIL;
    Node *x = root;
    Node *z = (Node *)malloc(sizeof(Node));

    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NIL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

void inorder(Node *u) {
    if (u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(int argc, char const* argv[])
{
    int n;
    char com[10];

    scanf("%d", &n);

    int x;
    for (int i = 0; i < n; i++) {
        scanf("%s", com);
        if (com[0] == 'f') {
            scanf("%d", &x);
            Node *t = find(root, x);
            if (t != NIL) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (strcmp(com, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(com, "print") == 0) {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        } else if (strcmp(com, "delete") == 0) {
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }

    return 0;
}
