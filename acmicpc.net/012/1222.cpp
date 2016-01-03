/**
 * 왠지 통과하면 안되는 코든데 통과한 느낌 (...) 1916MS 라니..
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int school[2000001];
int student[200000];

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", student + i);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 1; j * j <= student[i]; j++) {
      if (student[i] % j == 0) {
        school[j]++;
        if (j != student[i] / j) {
          school[student[i] / j]++;
        }
      }
    }
  }

  long long result = 0;

  for (int i = 1; i < 2000001; i++) {
    if (school[i] > 1) {
      result = max(result, school[i] * 1ll * i);
    }
  }

  printf("%lld\n", result);

  return 0;
}

