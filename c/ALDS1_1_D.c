#include <stdio.h>
#include <stdlib.h>

int min(int a, int b);
int max(int a, int b);

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    int *arr;
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ri = arr[0];
    int ans = arr[1] - ri;
    for (int i = 1; i < n; i++) {
        ans = max(ans, arr[i] - ri);
        ri = min(ri, arr[i]);
    }
    printf("%d\n", ans);
    free(arr);

    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}
