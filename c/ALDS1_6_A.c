#include <stdio.h>
#include <stdlib.h>

void countingSort(int *A, int *B);
#define MAX 10001
int C[MAX];
int n;

int main(int argc, char const* argv[])
{
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    int *B = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    countingSort(A, B);
    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", B[i]);
    }
    printf("\n");

    free(A);
    free(B);
    return 0;
}

void countingSort(int *A, int *B) {
    for (int i = 0; i < MAX; i++) C[i] = 0;
    for (int i = 0; i < n; i++) C[A[i]]++;
    for (int i = 1; i < MAX; i++) C[i] += C[i-1];

    for (int j = n-1; j >= 0; j--) {
        B[--C[A[j]]] = A[j];
    }
}
