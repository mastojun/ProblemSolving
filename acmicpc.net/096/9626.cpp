/**
 * 적당히 큰 맵의 (U, L) 부터 십자퍼즐을 넣고
 * 행+열 이 짝수면 #를 홀수면 .를 그런데 이미 글자가 있으면 스킵
 */
#include <cstdio>

using namespace std;

int M, N;
int U, L, R, D;

int main() {

  scanf("%d %d", &M, &N);
  scanf("%d %d %d %d", &U, &L, &R, &D);

  char puzzle[20][20] = {0};

  for (int i = 0; i < M; i++) {
    scanf("%s", &puzzle[i + U][0 + L]);
  }

  for (int i = 0; i < M + U + D; i++) {
    for (int j = 0; j < N + L + R; j++) {
      putchar(puzzle[i][j] ? puzzle[i][j] : (i + j) % 2 ? '.' : '#');
    }
    putchar('\n');
  }

  return 0;
}

