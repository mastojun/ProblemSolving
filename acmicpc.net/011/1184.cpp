/**
 * 간신히 통과함 -_ㅠ...
 *
 * N*N 을 움직이면서, 이 점을 기준으로 십자가로 땅을 4등분함. 이 점은 2사분면의 우하단 점을 나타냄
 * 각 영역은 부분합을 이용하여빠르게 계산하도록함..
 *
 * 제첨현황 보니 100ms 이하로 푸는데 이건 900ms 정도 -_ㅠ..
 */
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int N;
int profitMap[51][51];

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
      map<int, int> profits[2];
      // left top
      for (int k = i; k > 0; k--) {
        int sum = 0;
        for (int s = j; s > 0; s--) {
          sum += profitMap[i][s] - profitMap[k - 1][s];
          profits[0][sum]++;
        }
      }
      // right top
      for (int k = i; k > 0; k--) {
        int sum = 0;
        for (int s = j + 1; s <= N; s++) {
          sum += profitMap[i][s] - profitMap[k - 1][s];
          profits[1][sum]++;
        }
      }
      // left bottom
      for (int k = i + 1; k <= N; k++) {
        int sum = 0;
        for (int s = j; s > 0; s--) {
          sum += profitMap[k][s] - profitMap[i][s];
          result += profits[1][sum];
        }
      }
      // right bottom
      for (int k = i + 1; k <= N; k++) {
        int sum = 0;
        for (int s = j + 1; s <= N; s++) {
          sum += profitMap[k][s] - profitMap[i][s];
          result += profits[0][sum];
        }
      }
    }
  }

  printf("%d\n", result);

  return 0;
}

