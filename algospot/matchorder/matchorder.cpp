#include <cstdio>

#include <algorithm>
#include <functional>
using namespace std;

int russian[100];
int korean[100];

int main() {

  int C;
  scanf("%d", &C);

  while (C --> 0) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
      scanf("%d", russian + i);
    }
    for (int i = 0; i < N; i++) {
      scanf("%d", korean + i);
    }
    sort(russian, russian + N, greater<int>());
    sort(korean, korean + N, greater<int>());

    int result = 0;
    int russianIdx = 0;
    for (int i = 0; i < N; i++) {
      while (russianIdx < N && korean[i] < russian[russianIdx]) russianIdx++;
      if (russianIdx == N) break;
      result++;
      russianIdx++;
    }

    printf("%d\n", result);
  }

  return 0;
}
