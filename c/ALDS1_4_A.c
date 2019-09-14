#include <stdio.h>
#include <stdlib.h>

int linearSearch(int x, int n);
int S[100001];
int T[500];

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    // int *S = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    int q;
    scanf("%d", &q);
    // int *T = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    int ans = 0;
    for (int i = 0; i < q; i++) {
        if ( linearSearch(T[i], n) ) {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}

int linearSearch(int x, int n) {
    S[n] = x;
    int i = 0;
    while (S[i] != x) {
        i++;
    }
    return i != n;
}
