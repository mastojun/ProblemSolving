#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

int A, B, C;
char str[2][3001];
int dp[3001][3001];
int solve(int i, int j) {
  if (str[0][i] == 0 && str[1][j] == 0) return 0;

  int& ret = dp[i][j];
  if (ret != -1) return ret;

  if (str[0][i] == 0) return ret = solve(i, j + 1) + B;
  if (str[1][j] == 0) return ret = solve(i + 1, j) + B;

  return ret = max(solve(i + 1, j + 1) + (str[0][i] == str[1][j] ? A : C),
                max(solve(i + 1, j) + B, solve(i, j + 1) + B));
}

int main() {
  scanf("%d %d %d", &A, &B, &C);
  scanf("%s", str[0]);
  scanf("%s", str[1]);

  memset(dp, -1, sizeof(dp));

  printf("%d", solve(0, 0));
  return 0;
}
