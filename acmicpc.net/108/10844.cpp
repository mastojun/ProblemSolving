/**
 * simple dp!
 *
 * f(prev, len) = 길가 len이고 마지막 숫자가 prev인 숫자 뒤에 붙일 수 있는 계단 수의 수
 */
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000000;

int N;
int dp[10][100];

int solve(int prev, int len) {
  if (len == N) return 1;

  int& ret = dp[prev][len];
  if (ret != -1) return ret;

  ret = 0;
  if (prev < 9) ret += solve(prev + 1, len + 1);
  if (prev > 0) ret += solve(prev - 1, len + 1);

  return ret %= MOD;
}

int main() {
  scanf("%d", &N);

  memset(dp, -1, sizeof(dp));

  int result = 0;
  for (int i = 1; i < 10; i++) {
    result += solve(i, 1);
    result %= MOD;
  }

  printf("%d\n", result);

  return 0;
}

