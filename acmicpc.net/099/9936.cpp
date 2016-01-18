/*
 * DP 문제.
 *
 * 순서를 x증가 / y증가 순으로 도미노를 넣을 때 (x, y)에 넣는 방법은 2가지 (오른쪽으로 눞히기, 세우기) 와 스킵 총 3가지 중 하나를 선택 할 수 있다.
 *
 * 이렇게 하면 부분 문제가 변경 되기 때문에 변경된걸 status로 처리를 해서 cache할때 같이 사용하도록 함.
 *
 * 오답노트
 *  x == 3일때 status는 그대로 넘겨야 하는데 next(status)를 해서 오답을 받음
 *  도미노를 모두 사용해야 하므로 k != 0 이고 y == N 이면 답이 안되어야해서 충분히 작은수를 리턴해야함
 *  총 3개의 비트를 사용하므로 가짓수는 8가지 (7로 하면 안됨)
 */
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
int board[1000][3];
int cache[1000][3][1001][8];

int next(int status) {
  return (status << 1) & 7;
}

int putLast(int status) {
  return status | 1;
}

int putFirst(int status) {
  return status | 4;
}

int solve(int y, int x, int k, int status) {
  if (k == 0) return 0;
  if (y == N) return -987654321;
  if (x == 3) return solve(y + 1, 0, k, status);
  if (status & 4) return solve(y, x + 1, k, next(status));

  int& result = cache[y][x][k][status];
  if (result != INT_MIN) return result;

  result = solve(y, x + 1, k, next(status));

  if (x < 2 && (status & 2) == 0) {
    result = max(result, board[y][x] + board[y][x + 1] + solve(y, x + 1, k - 1, putFirst(next(status))));
  }
  if (y < N - 1) {
    result = max(result, board[y][x] + board[y + 1][x] + solve(y, x + 1, k - 1, putLast(next(status))));
  }

  return result;

}

int main() {
  scanf("%d %d", &N, &K);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &board[i][j]);
      for (int k = 0; k <= K; k++) {
        for (int s = 0; s <= 7; s++) {
          cache[i][j][k][s] = INT_MIN;
        }
      }
    }
  }

  printf("%d\n", solve(0, 0, K, 0));

  return 0;
}

