#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int selectionSort(int *A, int N);
void printArray(int *A, int N);

int main(int argc, char const* argv[])
{
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int cnt = selectionSort(A, N);
    printArray(A, N);
    printf("%d\n", cnt);

    free(A);
    return 0;
}

int selectionSort(int *A, int N) {
    int cnt = 0;
    for (int i = 0; i < N-1; i++) {
        int minidx = i;
        for (int j = i+1; j < N; j++) {
            if (A[j] < A[minidx]) {
                minidx = j;
            }
        }
        if (minidx != i) {
            swap(&A[i], &A[minidx]);
            cnt++;
        }
    }
    return cnt;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void printArray(int *A, int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}
