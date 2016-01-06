/**
 * 간신히 통과함 -_ㅠ...
 *
 * N*N 을 움직이면서, 이 점을 기준으로 십자가로 땅을 4등분함. 이 점은 2사분면의 우하단 점을 나타냄
 * 각 영역은 부분합을 이용하여빠르게 계산하도록함..
 *
 * 제첨현황 보니 100ms 이하로 푸는데 이건 900ms 정도 -_ㅠ..
 * 의 비밀을 솔루션 보고 알게됨 (...)
 *
 * 아래 수정된 코드처럼, profits 을 초기화 할때 이미 계산한곳만 초기화 하면 되는거였음 .
 * 같은 방식으로 map을 사용하면 시간초과 발생함 (map이 적어도 30배 느린듯..)
 */
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int N;
int profitMap[51][51];
int profits[5000000];
int main() {
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &profitMap[i][j]);
      profitMap[i][j] += profitMap[i - 1][j];
    }
  }

  int result = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      // left top
      for (int k = i; k > 0; k--) {
        int sum = 0;
        for (int s = j; s > 0; s--) {
          sum += profitMap[i][s] - profitMap[k - 1][s];
          profits[sum + 2500000]++;
        }
      }
      // right bottom
      for (int k = i + 1; k <= N; k++) {
        int sum = 0;
        for (int s = j + 1; s <= N; s++) {
          sum += profitMap[k][s] - profitMap[i][s];
          result += profits[sum + 2500000];
        }
      }
      // init
      for (int k = i; k > 0; k--) {
        int sum = 0;
        for (int s = j; s > 0; s--) {
          sum += profitMap[i][s] - profitMap[k - 1][s];
          profits[sum + 2500000]--;
        }
      }
      // right top
      for (int k = i; k > 0; k--) {
        int sum = 0;
        for (int s = j + 1; s <= N; s++) {
          sum += profitMap[i][s] - profitMap[k - 1][s];
          profits[sum + 2500000]++;
        }
      }
      // left bottom
      for (int k = i + 1; k <= N; k++) {
        int sum = 0;
        for (int s = j; s > 0; s--) {
          sum += profitMap[k][s] - profitMap[i][s];
          result += profits[sum + 2500000];
        }
      }
      for (int k = i; k > 0; k--) {
        int sum = 0;
        for (int s = j + 1; s <= N; s++) {
          sum += profitMap[i][s] - profitMap[k - 1][s];
          profits[sum + 2500000]--;
        }
      }
    }
  }

  printf("%d\n", result);

  return 0;
}

