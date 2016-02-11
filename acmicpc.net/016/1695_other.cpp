/**
 * 원 배열과 역배열의 LCS 를 제외한 것 만큼 더 추가하면 되는 문제였...
 */
#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

int N;
int nums[5000];
int cache[2][5000];

int solve() {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (nums[N - 1 - j] == nums[i]) {
        cache[i % 2][j] = j ? cache[(i + 1) % 2][j - 1] + 1 : 1;
      } else {
        cache[i % 2][j] = max(j ? cache[i % 2][j - 1] : 0, cache[(i + 1) % 2][j]);
      }
    }
  }

  return N - cache[(N - 1) % 2][N - 1];
}

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", nums + i);
  }

  printf("%d\n", solve());

  return 0;
}

