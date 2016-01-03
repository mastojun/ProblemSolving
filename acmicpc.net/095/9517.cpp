#include <cstdio>

using namespace std;

int K;
int N;

int solve() {
  int result = K;
  int remain = 3 * 60 + 30;
  for (int i = 0; i < N; i++) {
    int second;
    char action;
    scanf("%d %c", &second, &action);
    remain -= second;
    if (remain <= 0) return result;
    if (action == 'T') result++;
    if (result > 8) result = 1;
  }

  return result; //?
}

int main() {
  scanf("%d", &K);
  scanf("%d", &N);

  printf("%d\n", solve());

  return 0;
}

