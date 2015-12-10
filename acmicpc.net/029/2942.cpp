#include <cstdio>

using namespace std;

int r, g;

int gcd(int n, int m) {
    if(m == 0) return n;
    return gcd(m, n%m);
}

void solve(int n) {
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            printf("%d %d %d\n", i, r/i, g/i);
            if(i != n/i)
                printf("%d %d %d\n", n/i, r/(n/i), g/(n/i));
        }
    }
}

int main() {

    scanf("%d %d", &r, &g);
    solve(gcd(r, g));

    return 0;
}

