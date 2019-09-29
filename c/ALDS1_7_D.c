#include <stdio.h>
#include <stdlib.h>

int n, pos, idx;
int *pre, *post, *in;

int find(int x) {
    for (int i = 0; i < n; i++)
        if (in[i] == x) return i;
}

void rec(int l, int r) {
    if (l >= r) return;
    int root = pre[pos++];
    int m = find(root);
    rec(l, m);
    rec(m+1, r);
    post[idx++] = root;
}

int main(int argc, char const* argv[])
{
    scanf("%d", &n);

    pre = (int *)malloc(n * sizeof(int));
    in = (int *)malloc(n * sizeof(int));
    post = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    rec(0, n);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", post[i]);
    }
    printf("\n");

    return 0;
}
