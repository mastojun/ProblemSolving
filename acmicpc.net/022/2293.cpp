#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int coins[100];
int dp[10001];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] << endl;

    return 0;
}

