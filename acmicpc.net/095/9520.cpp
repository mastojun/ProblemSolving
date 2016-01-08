/**
 * 풀이보고 품
 *
 * 1번을 방문했다고 치면, 2번은 1번 바로 전에 방문하거나 바로 뒤에 방문할 수 있다
 * 즉 2 -> 1 순 혹은 1 -> 2 순으로만 방문이 가능하다.
 *
 * 3번은 이 리스트에서 왼쪽 혹은 오른쪽에만 붙을 수있다.
 * 즉 3 -> 2 -> 1 혹은 1 -> 2 -> 3 으로만 방문이 가능하며 그 외는 규칙에 어긋나게된다.
 *
 * 오답노트
 *  경로를 만드는 방법을 떠올리지 못함. 그것만 떠올렸다면 쉽게 풀 수 있는 문제였는데..
 *  이런건 어떻게 훈련하지?
 *
 */
#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

int N;

int city[1501][1501];
int dp[1501][1501];

int solve(int left, int right) {
  if (max(left, right) == N) return 0;

  int &ret = dp[left][right];
  if (ret != -1) return ret;

  int next = max(right, left) + 1;

  ret = min(city[right][next] + solve(next, left),
            city[left][next] + solve(right, next));

  return ret;
}

int main() {
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &city[i][j]);
    }
  }

  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(1, 1));

  return 0;
}

