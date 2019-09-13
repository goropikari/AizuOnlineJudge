#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char mark;
} Card;

void printArray(Card *cards, int N);
void bubbleSort(Card *cards, int N);
void selectionSort(Card *cards, int N);
void isStable(Card *cards, Card *srccards, int N);
void swap(Card *a, Card *b);

int main(int argc, char const* argv[])
{
    int N;
    scanf("%d", &N);
    Card *cards = (Card *)malloc(N * sizeof(Card));
    for (int i = 0; i < N; i++) {
        char card[2];
        scanf("%s", card);
        cards[i].mark = card[0];
        cards[i].num = card[1] - '0';
    }
    Card *cards2 = (Card *)malloc(N * sizeof(Card));
    memcpy(cards2, cards, N * sizeof(Card));

    bubbleSort(cards, N);
    printArray(cards, N);
    printf("Stable\n");

    selectionSort(cards2, N);
    printArray(cards2, N);
    isStable(cards, cards2, N);

    free(cards); free(cards2);

    return 0;
}


void printArray(Card *cards, int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%c%d", cards[i].mark, cards[i].num);
    }
    printf("\n");
};

void bubbleSort(Card *cards, int N) {
    for (int i = 1; i < N; i++) {
        for (int j = N-1; j >= i; j--) {
            if (cards[j-1].num > cards[j].num) {
                swap(&cards[j-1], &cards[j]);
            }
        }
    }
};

void selectionSort(Card *cards, int N) {
    for (int i = 0; i < N-1; i++) {
        int minidx = i;
        for (int j = i+1; j < N; j++) {
            if (cards[j].num < cards[minidx].num) {
                minidx = j;
            }
        }
        swap(&cards[minidx], &cards[i]);
    }
};

void isStable(Card *cards, Card *cards2, int N) {
    for (int i = 0; i < N; i++) {
        // 数字はソートされているからマークだけ比較すれば十分
        if (cards[i].mark != cards2[i].mark) {
            printf("Not stable\n");
            return;
        }
    }
    printf("Stable\n");
};

void swap(Card *a, Card *b) {
    Card c = *a;
    *a = *b;
    *b = c;
}
