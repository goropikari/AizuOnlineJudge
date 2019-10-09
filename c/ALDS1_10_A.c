#include <stdio.h>

#define MAX 50
long long int F[MAX];

long long int fib(int n) {
    if (n < 2) return F[n] = 1;
    if (F[n] != -1) return F[n];
    return F[n] = fib(n-1) + fib(n-2);
}

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) F[i] = -1;
    printf("%ld\n", fib(n));

    return 0;
}
