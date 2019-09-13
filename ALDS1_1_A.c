#include <stdio.h>
#include <stdlib.h>

void insertSort(int *A, int N);
void printArray(int *A, int N);

int main(int argc, char const* argv[])
{
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    insertSort(A, N);

    return 0;
}

void insertSort(int *A, int N) {
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray(A, N);
    }
    printArray(A, N);
}

void printArray(int *A, int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}
