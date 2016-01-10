#include <cstdio>

using namespace std;
int T;
int N;
int P;
int boxes[100000];

int solve() {
  long long sum = 0;
  for (int left = 0, right = 0; right < N; right++) {
    sum += boxes[right];
    while (sum > P) {
      sum -= boxes[left++];
    }
    sum += right - left;
  }

  return sum;
}

int main() {
  scanf("%d", &T);

  for (int C = 1; C <= T; C++) {
    scanf("%d %d", &N, &P);
    for (int i = 0; i < N; i++) {
      scanf("%d", boxes + i);
    }

    printf("Case #%d: %d\n", C, solve());
  }

  return 0;
}

