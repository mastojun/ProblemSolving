/**
 * 처음엔 f(n, m) = nxm 의 격자를 2x1로 채우는걸로 정의하고
 *  f(n, m) = sum i ~ n f(n - i, m) * f(i) 로 해봤는데 순환참조가 발생해서 Fail
 *  아무리 고민해도 안되서 검색해보니 http://slidehot.com/resources/baekjoon-online-judge-1648.471337/ 이걸 발견
 *  두번째 슬라이드의 go(N, S) = N번째 칸을 채울 것이고, N번째 칸부터 칸 M개의~ 설명읽고 아! 하여 품
 *
 *  solve(N, S) = N번째 칼을 채울 것이고, N - M 부터 N - 1 까지의 상태가 S일때의 경우의 수 로 품
 *  이전 상태가 없는 n == 0인 경우에 대한 예외처리 때문에 더 복잡한듯 (-_-;;)
 *
 *  오래전 topcoder에서 벽에 무언가 배열하는 문제도 이런 식으로 푸는거였는데 풀이가 안떠오르다니 읃리ㅏ32러ㅣㅏ
 */
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

int dp[14][14][1<<14];

bool isSet(int status, int pos) {
  return (status >> (M - pos - 1)) & 1;
}

int append(int status, vector<int> blocks) {
  for (int block : blocks) {
    status <<= 1;
    status |= block;
    status &= (1 << M) - 1;
  }

  return status;
}

int solve(int n, int m, int status) {
  if (n == N) {
    return status == (1 << M) -1;
  }
  if (m == M) {
    return solve(n + 1, 0, status);
  }
  if (m > M) {
    return 0;
  }

  int& result = dp[n][m][status];
  if (result != -1) {
    return result;
  }

  result = 0;

  if (n == 0) {
    result += solve(n, m + 2, append(status, {1, 1}));
    result += solve(n, m + 1, append(status, {0}));
  } else if (isSet(status, 0)) {
    if (isSet(status, 1)) {
      result += solve(n, m + 2, append(status, {1, 1}));
    }
    result += solve(n, m + 1, append(status, {0}));
  } else if (!isSet(status, 0)) {
    result += solve(n, m + 1, append(status, {1}));
  }

  return result %= 9901;
}

int main() {
  scanf("%d %d", &N, &M);

  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(0, 0, 0));

  return 0;
}

