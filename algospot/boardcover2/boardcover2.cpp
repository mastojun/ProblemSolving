#include <cstdio>

#include <algorithm>

using namespace std;

int T;
int H, W, R, C;
int limit;
char board[10][11];
char block[4][10][11];
int blockCount;

void generateRotateBlocks(int idx, int R, int C) {
  for (int i = 0; i < C; i++) {
    for (int j = R - 1; j >= 0; j--) {
      block[idx][i][R - 1 - j] = block[idx - 1][j][i];
    }
  }
}

bool canPut(int y, int x, int i) {
  int r = (i & 1) == 0 ? R : C;
  int c = (i & 1) == 0 ? C : R;
  if (r - 1 + y >= H) return false;
  if (c - 1 + x >= W) return false;

  for (int h = 0; h < r; h++) {
    for (int w = 0; w < c; w++) {
      if (block[i][h][w] == '.') continue;
      if (board[y + h][x + w] != '.') return false;
    }
  }

  return true;
}

void put(int y, int x, int i, char ch) {
  int r = (i & 1) == 0 ? R : C;
  int c = (i & 1) == 0 ? C : R;

  for (int h = 0; h < r; h++) {
    for (int w = 0; w < c; w++) {
      if (block[i][h][w] == '#') board[y + h][x + w] = ch;
    }
  }
}

void put(int y, int x, int i) {
  put(y, x, i, '#');
}

void off(int y, int x, int i) {
  put(y, x, i, '.');
}

int result;

bool dontNeedToGo(int count, int remain) {

  return remain / blockCount + count <= result;
}

void go(int y, int x, int count, int remain) {
  if (y == limit) {
    result = max(result, count);
    return;
  }
  if (x == W) {
    go(y + 1, 0, count, remain);
    return;
  }
  if (dontNeedToGo(count, remain)) {
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (canPut(y, x, i)) {
      put(y, x, i);
      go(y, x + 1, count + 1, remain - blockCount);
      off(y, x, i);
    }
  }
  go(y, x + 1, count, remain - (board[y][x] == '.' ? 1 : 0));
}

int main() {
  scanf("%d", &T);
  while (T --> 0) {
    scanf("%d %d %d %d", &H, &W, &R, &C);
    limit = H - min(R, C) + 1;
    int remainBlank = 0;
    for (int i = 0; i < H; i++) {
      scanf("%s", board[i]);
      for (int j = 0; board[i][j]; j++) {
        if (board[i][j] == '.') remainBlank++;
      }
    }
    blockCount = 0;
    for (int i = 0; i < R; i++) {
      scanf("%s", block[0][i]);
      for (int j = 0; block[0][i][j]; j++) {
        if (block[0][i][j] == '#') blockCount++;
      }
    }
    generateRotateBlocks(1, R, C);
    generateRotateBlocks(2, C, R);
    generateRotateBlocks(3, R, C);

    result = 0;
    go(0, 0, 0, remainBlank);
    printf("%d\n", result);
  }

  return 0;
}

