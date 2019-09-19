#include <stdio.h>
#include <stdlib.h>

#define MAX 500000
#define SENTINEL 1000000001
int S[MAX];
int L[MAX / 2 + 2];
int R[MAX / 2 + 2];
int cnt;

void mergeSort(int S[], int left, int right);
void merge(int S[], int left, int mid, int right);

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    mergeSort(S, 0, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", S[i]);
    }
    printf("\n%d\n", cnt);

    return 0;
}

void mergeSort(int S[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}

void merge(int S[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) L[i] = S[left + i];
    for (int i = 0; i < n2; i++) R[i] = S[mid + i];

    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int li = 0, ri = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        S[k] = (L[li] <= R[ri]) ? L[li++] : R[ri++];
    }
}
