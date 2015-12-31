#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int T;
int N;

struct LunchBox {
  int useSecond;
  int eatSecond;
};

LunchBox boxes[10000];

bool orderByEatSecond(const LunchBox& lhs, const LunchBox& rhs) {
  return lhs.eatSecond > rhs.eatSecond;
}

int main() {
  scanf("%d", &T);

  while (T --> 0) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &boxes[i].useSecond);
    }
    for (int i = 0; i < N; i++) {
      scanf("%d", &boxes[i].eatSecond);
    }

    sort(boxes, boxes + N, orderByEatSecond);

    int result = 0;
    int usedSecond = 0;

    for (int i = 0; i < N; i++) {
      result = max(result, usedSecond + box.useSecond + box.eatSecond);
      usedSecond += box.useSecond;
    }

    printf("%d\n", result);
  }

  return 0;
}

