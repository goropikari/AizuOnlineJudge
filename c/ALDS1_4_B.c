#include <stdio.h>

int S[100000];
int T[50000];

int binarySearch(int A[], int x, int n);

int main(int argc, char const* argv[])
{
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) scanf("%d", &T[i]);

    int ans = 0;
    for (int i = 0; i < q; i++) {
        if (binarySearch(S, T[i], n)) {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}

int binarySearch(int A[], int x, int n) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (r + l) / 2;
        if (A[mid] == x) {
            return 1;
        } else if (A[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return 0;
}
