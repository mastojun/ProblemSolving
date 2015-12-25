#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int wine[10000];

int solve(int idx, int len) {
    if (idx >= n) return 0;

    int result = 0;

    result = solve(idx + 1, 0);
    if (len < 2) result = max(result, wine[idx] + solve(idx + 1, len + 1));

    return result;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", wine + i);
    }

    printf("%d\n", solve(0, 0));

    return 0;
}

