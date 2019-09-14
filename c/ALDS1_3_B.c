#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int time;
} Work;

#define MAX_SIZE 200000
Work queue[MAX_SIZE];
int head, tail;

void enqueue(Work x);
Work dequeue();
int min(int a, int b);

int main(int argc, char const* argv[])
{
    int n, q;
    scanf("%d%d", &n, &q);

    char str[100];
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        scanf("%d", &x);
        Work work;
        strncpy(work.name, str, sizeof(str));
        work.time = x;
        enqueue(work);
    }

    int ans = 0;
    while (head != tail) {
        Work w = dequeue();
        int t = min(w.time, q);
        ans += t;
        w.time -= t;
        if (w.time > 0) {
            enqueue(w);
        } else {
            printf("%s %d\n", w.name, ans);
        }
    }

    return 0;
}

void enqueue(Work x) {
    queue[tail] = x;
    tail = (tail + 1) % MAX_SIZE;
}

Work dequeue() {
    Work x = queue[head];
    head = (head + 1) % MAX_SIZE;
    return x;
}

int min(int a, int b) {
    return a < b ? a : b;
}
