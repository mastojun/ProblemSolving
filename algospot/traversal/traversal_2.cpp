#include <cstdio>

using namespace std;

int n;
int in[100];
int pre[1001];
int post[100];
int postIdx;

void solve(int left, int right) {
  if (left >= right) return;
  int root = -1;
  int minimum = 10000;

  for (int i = left; i < right; i++) {
    if (pre[in[i]] < minimum) {
      minimum = pre[in[i]];
      root = i;
    }
  }

  solve(left, root);
  solve(root + 1, right);
  post[postIdx++] = in[root];
}

int main() {
  int c;
  scanf("%d", &c);
  while (c --> 0) {
    scanf("%d", &n);
    postIdx = 0;
    for (int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      pre[num] = i;
    }
    for (int i = 0; i < n; i++) scanf("%d", in + i);
    solve(0, n);
    for (int i = 0; i < n; i++) printf("%d ", post[i]);
  }

  return 0;
}

