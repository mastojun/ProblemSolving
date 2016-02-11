#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

int N;
int nums[5000];
int cache[5000][5000];

int solve(int l, int r) {
  if (l >= r) return 0;

  int& ret = cache[l][r];
  if (ret != -1) return ret;

  if (nums[l] == nums[r]) return ret = solve(l + 1, r - 1);
  else return ret = 1 + min(solve(l, r - 1), solve(l + 1, r));
}

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", nums + i);
  }

  memset(cache, -1, sizeof(cache));
  printf("%d\n", solve(0, N - 1));

  return 0;
}

