#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

int n;
int students[1000];
int cache[1000];

int solve(int idx) {
  if (idx == n) return 0;

  int& ret = cache[idx];
  if (ret != -1) return ret;

  int m = students[idx];
  int M = students[idx];

  ret = 0;

  for (int i = idx; i < n; i++) {
    m = min(m, students[i]);
    M = max(M, students[i]);
    ret = max(ret, M - m + solve(i + 1));
  }

  return ret;
}

int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", students + i);
  }

  memset(cache, -1, sizeof(cache));
  printf("%d\n", solve(0));

  return 0;
}


