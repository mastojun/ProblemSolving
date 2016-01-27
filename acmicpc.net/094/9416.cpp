#include <cstdio>

using namespace std;

long long dp[101];

long long solve(int n) {
  if (n <= 3) return 1;
  if (n <= 5) return 2;

  long long& ret = dp[n];
  if (ret != 0) return ret;

  return ret = solve(n - 1) + solve(n - 5);
}

int main() {
  int t;
  scanf("%d", &t);

  while (t --> 0) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", solve(n));
  }

  return 0;
}

