/**
 * 2156문제랑 비슷하나, 마지막 계단은 반드시 밟아야 하는점이 다름
 * 마지막계단을 반드시 밟아야 한다는점이 다른점.
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int steps[300];
int dp[300][3];

int solve(int pos, int count) {
    if (pos == n - 1) {
        return count >= 2 ? -987654321 : steps[pos];
    }

    int& result = dp[pos][count];
    if (result != -1) return result;

    if (count < 2) {
        result = max(result, steps[pos] + solve(pos + 1, count + 1));
    }
    if (count != 0 || pos == 0) {
        result = max(result, solve(pos + 1, 0));
    }

    return result;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", steps + i);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, 0));

    return 0;
}

