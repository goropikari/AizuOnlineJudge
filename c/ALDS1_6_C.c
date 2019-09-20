#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char mark;
    int val;
} Card;

int partition(Card *A, int p, int r);
void swap(Card *a, Card *b);
void quickSort(Card *A, int p, int r);
void mergeSort(Card *S, int left, int right);
void merge(Card *S, int left, int mid, int right);

#define MAX 1000000
#define SENTINEL 100000001
Card S[MAX];
Card L[MAX / 2 + 2];
Card R[MAX / 2 + 2];

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d\n", &n);
    // scanf("%d", &n);
    Card *A = (Card *)malloc(n * sizeof(Card));
    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &A[i].mark, &A[i].val);
        S[i] =  A[i];
        // scanf("%c %d", &A[i].mark, &A[i].val);
    }

    quickSort(A, 0, n-1);
    mergeSort(S, 0, n);
    int truth = 1;
    for (int i = 0; i < n; i++) {
        if (A[i].mark != S[i].mark) {
            printf("Not stable\n");
            truth = 0;
            break;
        }
    }
    if (truth) printf("Stable\n");

    // printf("A\n");
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", A[i].mark, A[i].val);
    }

    // printf("\nS\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%c %d\n", S[i].mark, S[i].val);
    // }
    free(A);
    return 0;
}

int partition(Card *A, int p, int r) {
    int x = A[r].val;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].val <= x) {
            swap(&A[++i], &A[j]);
        }
    }
    swap(&A[i+1], &A[r]);
    return i+1;
}

void swap(Card *a, Card *b) {
    Card tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(Card *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void mergeSort(Card *S, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}

void merge(Card *S, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) L[i] = S[left + i];
    for (int i = 0; i < n2; i++) R[i] = S[mid + i];

    L[n1].val = SENTINEL;
    R[n2].val = SENTINEL;
    int li = 0, ri = 0;
    for (int k = left; k < right; k++) {
        S[k] = (L[li].val <= R[ri].val) ? L[li++] : R[ri++];
    }
}
