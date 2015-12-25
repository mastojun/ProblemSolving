/**
 * f(i, l) = max(wine[i] + f(i + 1, l + 1) 단 l이 2미만), f(i + 1, 0));
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int wine[10000];
int dp[10000][3];

int solve(int idx, int len) {
    if (idx >= n) return 0;

    int& result = dp[idx][len];
    if (result != -1) return result;

    result = solve(idx + 1, 0);
    if (len < 2) result = max(result, wine[idx] + solve(idx + 1, len + 1));

    return result;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", wine + i);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, 0));

    return 0;
}

