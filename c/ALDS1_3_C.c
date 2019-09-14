#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int val;
    struct Item *prev;
    struct Item *next;
};
typedef struct Item Item;

void insert(int x);
void delete(int x);
void deleteFirst();
void deleteLast();
void printList();

Item head;

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);

    head.prev = &head;
    head.next = &head;

    char op[20];
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) { // delete
            scanf("%d", &x);
            delete(x);
        } else if (op[6] == 'F') { // deleteFirst
            deleteFirst();
        } else { // deleteLast
            deleteLast();
        }
    }

    printList();
    return 0;
}

void insert(int x) {
    Item *item = (Item *)malloc(sizeof(Item));
    item->val = x;
    item->next = head.next;
    head.next = item;
    item->next->prev = item;
    item->prev = &head;
}

void delete(int x) {
    Item *h = &head;
    while ((h = h->next) != &head) {
        if (h->val == x) {
            h->prev->next = h->next;
            h->next->prev = h->prev;
            free(h);
            break;
        }
    }
}

void deleteFirst() {
    Item *f = head.next;
    head.next = f->next;
    f->next->prev = &head;
    free(f);
}

void deleteLast() {
    Item *l = head.prev;
    l->prev->next = &head;
    head.prev = l->prev;
    free(l);
}

void printList() {
    Item *h = &head;
    int i = 0;
    while ((h = h->next) != &head) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", h->val);
        i++;
    }
    printf("\n");
}
