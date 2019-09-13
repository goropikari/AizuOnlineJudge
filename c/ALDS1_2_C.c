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

    Card *bubblecards = (Card *)malloc(N * sizeof(Card));
    memcpy(bubblecards, cards, N * sizeof(Card));
    bubbleSort(bubblecards, N);
    printArray(bubblecards, N);
    isStable(bubblecards, cards, N);
    free(bubblecards);

    Card *selectioncards = (Card *)malloc(N * sizeof(Card));
    memcpy(selectioncards, cards, N * sizeof(Card));
    selectionSort(selectioncards, N);
    printArray(selectioncards, N);
    isStable(selectioncards, cards, N);
    free(selectioncards);

    free(cards);

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

void isStable(Card *cards, Card *srccards, int N) {
    Card *tmpcards = (Card *)malloc(N * sizeof(Card));
    memcpy(tmpcards, srccards, N * sizeof(Card));
    bubbleSort(tmpcards, N);
    for (int i = 0; i < N; i++) {
        if (cards[i].num != tmpcards[i].num || cards[i].mark != tmpcards[i].mark) {
            printf("Not stable\n");
            free(tmpcards);
            return;
        }
    }
    printf("Stable\n");
    free(tmpcards);
};

void swap(Card *a, Card *b) {
    Card c = *a;
    *a = *b;
    *b = c;
}
