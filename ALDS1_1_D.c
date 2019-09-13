#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    int *arr;
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ri = arr[0], rj = arr[1];
    int ans = rj - ri;
    for (int i = 1; i < n; i++) {
        if (ans < arr[i] - ri) {
            ans = arr[i] - ri;
        } else if (arr[i] < ri){
            ri = arr[i];
        }
    }
    printf("%d\n", ans);
    free(arr);

    return 0;
}
