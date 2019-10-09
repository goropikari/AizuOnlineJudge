#include <stdio.h>
#include <stdlib.h>

#define MAX 2000000
#define INFTY (1 << 30)

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

int extract() {
    int maxv;
    if (H < 1) return -INFTY;
    maxv = A[1];
    A[1] = A[H--];
    maxHeapify(1);
    return maxv;
}

void increaseKey(int i, int key) {
    if (key < A[i]) return;
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i]) {
        swap(&A[i], &A[i / 2]);
        i /= 2;
    }
}

void insert(int key) {
    H++;
    A[H] = - INFTY;
    increaseKey(H, key);
}

int main(int argc, char const* argv[])
{
    int key;
    char com[10];

    while (1) {
        scanf("%s", com);
        if (com[0] == 'e' && com[1] == 'n') break; // end
        if (com[0] == 'i') { // insert
            scanf("%d", &key);
            insert(key);
        } else { // extract
            printf("%d\n", extract());
        }
    }

    return 0;
}
