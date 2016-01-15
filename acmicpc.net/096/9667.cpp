/**
 * 문제에서 알 수 있는 사실들은
 *   1) 1개로 만들거나 100,000 개로 만들기까지 가능함
 *   2) n개로 나눌때는 n - 1번 자르기가 필요함
 *   3) n개로 자르고 나서는 n의 배수들은 n개로 자르는데 필요한 횟수만큼은 자를 필요 없음 (그 위치는 이미 잘렸으므로)
 *
 * 라는 사실을 알 수 있다.
 * 2) 의 규칙에 따라서 100,000 개에 대한 자르기 필요한 횟수 테이블을 만들고 난 후,
 * 3) 의 규칙에 따라서 1부터 100,000 까지 순회하며 배수들에게 자르는 횟수를 빼버리면 중복으로 발생하는 자르기를 제거할 수 있다.
 *
 * 이렇게 만들어진 테이블에서 주어진 입력들의 약수에 해당하는 위치의 값들을 더하면 되는데,
 * 위 테이블을 만드는 과정에 이걸 합쳐서 다른 계산을 하지 않아도 되도록 했다. (자세한건 코드 참고)
 *
 * 시간복잡도는 O(maxN * log(maxN)) 인데 N을 100,000 으로 고정했...
 * 처음부터 coci 2013/2014 contest #1 의 5번과 비슷하게 접근해서 풀이를 떠올릴 수 있었음.
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const int LEN = 100000;

bool size[LEN + 1];
int table[LEN + 1];

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i <= n; i++) {
    int c;
    scanf("%d", &c);
    size[c] = true;
  }
  for (int i = 1; i <= LEN; i++) {
    table[i] = i - 1;
  }

  long long result = 0;
  for (int i = 1; i <= LEN; i++) {

    bool find = false;

    for (int j = 1; i * j <= LEN; j++) {
      if (size[i * j]) {
        find = true;
      }
      if (j > 1) {
        table[i * j] -= table[i];
      }
    }

    if (find) {
      result += table[i];
    }
  }

  printf("%lld\n", result);

  return 0;
}

