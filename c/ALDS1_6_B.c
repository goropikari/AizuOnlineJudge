#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int p, int r);
void swap(int *a, int *b);

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int idx = partition(A, 0, n-1);
    for (int i = 0; i < n; i++) {
        if ( i ) {
            printf(" ");
        }
        if (i == idx) {
            printf("[");
        }
        printf("%d", A[i]);
        if (i == idx) {
            printf("]");
        }
    }
    printf("\n");

    return 0;
}

int partition(int *A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            swap(&A[++i], &A[j]);
        }
    }
    swap(&A[i+1], &A[r]);
    return i+1;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
