#include <stdio.h>
#define MAX 2000000

int H, A[MAX+1];

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int i) {
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if (l <= H && A[l] > A[i]) largest = l;
    else largest = i;
    if (r <= H && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        maxHeapify(largest);
    }
}

int main(int argc, char const* argv[])
{
    scanf("%d", &H);

    for (int i = 1; i <= H; i++) scanf("%d", &A[i]);
    for (int i = H / 2; i >= 1; i--) maxHeapify(i);
    for (int i = 1; i <= H; i++) printf(" %d", A[i]);
    printf("\n");

    return 0;
}
