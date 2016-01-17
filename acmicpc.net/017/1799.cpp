/**
 * backtracking 문제, 이분매칭으로 풀 수 있다는데 이분매칭을 모르므로 패스
 *
 * 빠른 해결을 위한 첫번째 팁으로는 대각선의 위치를 한번에 접근할 수 있는 slash, backslash 변수를 두어
 * x - y + n, x + y 로 둘 수 있는지 확인하는 것인데, 이것만해서는 제한시간내에 풀리지 않음.
 *
 * 두번째는, 서로 영향을 주는 말판의 위치는 x + y 가 홀수는 홀수끼리, 짝수는 짝수끼리만 영향을 주는걸로 풀 수 있음.
 * (체스 판에서 검은칸은 검은칸만 갈 수 있고, 흰 칸은 흰칸만 갈 수 있는것과 같은..)
 * 이러면 탐색을 해야 하는 공간의 수가 반으로 줄어 제한시간 내에 풀리나..
 *
 * 시간 복잡도는 어떻게 계산해야 하지?
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int board[10][10];
bool slash[21];
bool backslash[21];

int solve(int y, int x, int c = 0) {
  if (y == n) return 0;
  if (x == n) return solve(y + 1, 0, c);
  if ((y + x) % 2 != c) return solve(y, x + 1, c);
  if (board[y][x] == 0) return solve(y, x + 1, c);
  if (slash[x - y + n]) return solve(y, x + 1, c);
  if (backslash[x + y]) return solve(y, x + 1, c);

  slash[x - y + n] = true;
  backslash[x + y] = true;

  int result = solve(y, x + 1, c) + 1;

  slash[x - y + n] = false;
  backslash[x + y] = false;

  result = max(result, solve(y, x + 1, c));

  return result;
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  printf("%d\n", solve(0, 0, 0) + solve(0, 1, 1));

  return 0;
}

