/*
 * JMbook 을 보고 블록이 있는곳의 위치를 저장하는 배열을 만들고
 * 중복제거를 하는 최적화 처리를 함.
 *
 * 상대 좌표이기 때문에 현재 board의 상태가 넣을 수 없는곳이면 스킵할 수 있게 되었고,
 * 중복제거를 해서 회전해도 같은경우 무시할 수 있어서 속도가 빨라짐.
 *
 * 그러다 알고스팟 페이지의 리플에 있는 아래 입력은 여전히 너무 느림
 * 1
 * 10 10 2 2
 * .....#...#
 * ..#..#..##
 * .###.#.###
 * ..#..#..##
 * .....#...#
 * ##########
 * #####...##
 * #.###..##.
 * #..##.##..
 * #...##....
 * ##
 * #.
 */
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

using namespace std;

int T;
int H, W, R, C;
int limit;
char board[10][11];
char block[4][10][11];
int blockCount;

vector<vector<pair<int,int>>> blocks;

void generateRotateBlocks(int idx, int R, int C) {
  for (int i = 0; i < C; i++) {
    for (int j = R - 1; j >= 0; j--) {
      block[idx][i][R - 1 - j] = block[idx - 1][j][i];
    }
  }
}

void generateBlocksVector() {
  generateRotateBlocks(1, R, C);
  generateRotateBlocks(2, C, R);
  generateRotateBlocks(3, R, C);

  blocks.clear();
  for (int i = 0; i < 4; i++) {
    vector<pair<int,int>> b;
    int firstX = -1;
    int firstY = -1;
    for (int y = 0; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        if (block[i][y][x] == '#') {
          if (firstX == -1) {
            firstX = x;
            firstY = y;
          }
          b.push_back(make_pair(y - firstY, x - firstX));
        }
      }
    }
    blocks.push_back(b);
  }

  sort(blocks.begin(), blocks.end());
  blocks.erase(unique(blocks.begin(), blocks.end()), blocks.end());
}

bool canPut(int y, int x, int i) {
  for (auto point : blocks[i]) {
    int py = y + point.first;
    if (py < 0 || py >= H) return false;
    int px = x + point.second;
    if (px < 0 || px >= W) return false;
    if (board[y + point.first][x + point.second] != '.') return false;
  }

  return true;
}

void put(int y, int x, int i, char ch) {
  for (auto point : blocks[i]) {
    board[y + point.first][x + point.second] = ch;
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
  if (board[y][x] != '.') {
    go(y, x + 1, count, remain);
    return;
  }
  if (dontNeedToGo(count, remain)) {
    return;
  }

  for (int i = 0; i < blocks.size(); i++) {
    if (canPut(y, x, i)) {
      put(y, x, i);
      go(y, x + 1, count + 1, remain - blockCount);
      off(y, x, i);
    }
  }
  go(y, x + 1, count, remain - 1);
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
    memset(block, 0, sizeof(block));
    blockCount = 0;
    for (int i = 0; i < R; i++) {
      scanf("%s", block[0][i]);
      for (int j = 0; block[0][i][j]; j++) {
        if (block[0][i][j] == '#') blockCount++;
      }
    }

    generateBlocksVector();

    result = 0;
    go(0, 0, 0, remainBlank);
    printf("%d\n", result);
  }

  return 0;
}

