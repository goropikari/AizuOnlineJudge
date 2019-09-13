#include <stdio.h>
#include <stdlib.h>

void shellSort(int *A, int N);

int cnt;

int main(int argc, char const* argv[])
{
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    shellSort(A, N);
    printf("%d\n", cnt);
    for (int i = 0; i < N; i++) {
        printf("%d\n", A[i]);
    }

    free(A);
    return 0;
}

void insertionSort(int *A, int N, int g) {
    for (int i = g; i < N; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int *A, int N) {
    cnt = 0;
    int m = 0, g = 1;
    while (g <= N) {
        g = 3 * g + 1;
        m++;
    }
    printf("%d\n", m);

    int *G = (int *)malloc(m * sizeof(int));
    G[0] = 1;
    for (int i = 0; i < m-1; i++) {
        G[i+1] = 3*G[i] + 1;
    }
    for (int i = m-1; i >= 0; i--) {
        if (i < m-1) printf(" ");
        printf("%d", G[i]);
    }
    printf("\n");

    for (int i = m-1; i >= 0; i--) {
        insertionSort(A, N, G[i]);
    }

    free(G);
}
