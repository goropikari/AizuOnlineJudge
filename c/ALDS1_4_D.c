#include <stdio.h>

#define MAX 100000
typedef long long ll;

int n, k;
ll T[MAX];

int check(ll P) {
    int i = 0;
    for (int j = 0; j < k; j++) {
        ll s = 0;
        while (s + T[i] <= P) {
            s += T[i];
            i++;
            if (i == n) return n;
        }
    }
    return i;
}

int solve() {
    ll left = 0;
    ll right = 100000 * 10000;
    ll mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        int v = check(mid);
        if (v >= n) right = mid;
        else left = mid;
    }

    return right;
}

int main(int argc, char const* argv[])
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &T[i]);
    }
    ll ans = solve();
    printf("%ld\n", ans);

    return 0;
}
