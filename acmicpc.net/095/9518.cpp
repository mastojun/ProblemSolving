#include <cstdio>
#include <algorithm>

using namespace std;

int R, S;
char chair[50][51];

void input() {
  scanf("%d %d", &R, &S);
  for (int i = 0; i < R; i++) {
    scanf("%s", chair[i]);
  }
}

int shake(int y, int x) {
  int result = 0;
  for (int i = -1; i <= 1; i++) {
    if (y + i < 0 || y + i >= R) continue;
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;
      if (x + j < 0 || x + j >= S) continue;
      result += chair[y + i][x + j] == 'o';
    }
  }
  return result;
}

int main() {

  input();

  int result = 0;
  int add = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < S; j++) {
      if (chair[i][j] == 'o') {
        result += shake(i, j);
      } else {
        add = max(add, shake(i, j));
      }
    }
  }

  printf("%d\n", result / 2 + add);

  return 0;
}

