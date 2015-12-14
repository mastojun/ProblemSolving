#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int coins[100];
int dp[10001][100];

int solve(int money, int coinIdx) {
    if(money == 0) return 1;
    if(money < 0) return 0;

    int& result = dp[money][coinIdx];
    if(result != -1) return result;

    result = 0;

    for (int i = coinIdx; i < n; i++) {
        result += solve(money - coins[i], i);
    }

    return result;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(k, 0) << endl;

    return 0;
}

