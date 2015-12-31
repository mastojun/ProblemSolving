/**
 * m_1, m_2
 * e_1, e_2
 * 의 도시락들이 있다고 했을 때,
 * 1 -> 2 순으로 먹을 경우 max(m_1 + e_1, m_1 + m_2 + e_2) 의 시간이 걸리며---- (1)
 * 2 -> 1 순으로 먹을 경우 max(m_2 + e_2, m_2 + m_1 + e_1) 의 시간이 걸린다---- (2)
 *
 * 따라서 저 식의 결과가 작은 순으로 정렬을 해도 답은 나온다. 단 입력에 대한 경계가 주어지지 않았기 때문에 합 연산을 할때 integer overflow를 고려해야 한다.
 *
 * 좀더 수식을 살펴보면..
 * (1)의 첫번째 값은 (2)의 두번째 값보다 항상 m_2만큼 작으며, (1)의 두번째 값은 (2)의첫번재 값보다 항상m_1만큼 작다.
 * 만약 (1)의 max가 첫번째 값이면 (2) 의 max는 두번째 값일 수 밖에 없으며, 이때 (1) < (2) 이므로 1 -> 2순으로 하는게 옳다.
 *  이때 e_1 > m_2 + e_2 이므로 e_1 > e_2 를 만족한다. ---- (3)
 * 만약 (1)의 max가 두번째 값이고 (2) 의 max도 두번째 값이면 (1) 과 (2)의 대소는 e_1 과 e_2에 따라 다르며, e_x가 더 작은값쪽의 max가 더 작으므로, 더 큰 e_x를 먼저 하는쪽이 이득이다. ---- (4)
 * 나머지 2경우에 대해서는 앞의 (3), (4)의 역과 동일하므로 결론적으로 e의 값이 큰 값부터 먼저 하는게 이득임을 알 수 있다.
 *
 */

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

