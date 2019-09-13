#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int *A, int N);
void printArray(int *A, int N);
void swap(int *a, int *b);

int main(int argc, char const* argv[])
{
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int cnt = bubbleSort(A, N);
    printArray(A, N);
    printf("%d\n", cnt);

    return 0;
}

int bubbleSort(int *A, int N) {
    int flag = 1;
    int i = 0;
    int cnt = 0;
    while (flag) {
        flag = 0;
        for (int j = N-1; j > i; j--) {
            if (A[j-1] > A[j]) {
                swap(&A[j-1], &A[j]);
                flag = 1;
                cnt++;
            }
        }
        i++;
    }

    return cnt;
}

void printArray(int *A, int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
