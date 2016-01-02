/**
 * 소시지의 길이를 1로 하면, 평론가 한명에게 N / M 길이만큼 줘야 합니다.
 * 따라서 m명에게 나누어 주었을 경우 N / M * m 만큼의 길이의 소시지를
 * 나누어 준게 되는데, 이 수가 정수가 되는 경우가 아니면 소시지를 잘라야한다.
 *
 * N / M * m 이 정수라는 것은 N * m / M 이 정수 즉, N * m mod M이 0이란 의미이므로
 * 이를 이용해서 아래와 같이 풀 수 있다.
 */
#include <cstdio>

using namespace std;


int main() {

  int N, M;

  scanf("%d %d", &N, &M);

  int result = 0;

  for (int i = 1; i <= M; i++) {
    if (N * i % M) {
      result++;
    }
  }

  printf("%d", result);

  return 0;
}

