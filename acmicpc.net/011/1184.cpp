#include <cstdio>
#include <map>

using namespace std;

int N;
int profitMap[51][51];

struct Point {
  int x, y;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  bool operator==(const Point& other) const {
    return other.x == x && other.y == y;
  }

  bool operator<(const Point& other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
};

map<int, map<Point, int>> profits[4];

int main() {
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &profitMap[i][j]);
      profitMap[i][j] += profitMap[i - 1][j];
    }
  }

  int result = 0;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      for (int k = i; k <= N; k++) {
        sum = 0;
        for (int s = j; s <= N; s++) {
          sum += profitMap[k][s] - profitMap[i - 1][s];

          result += profits[0][sum][Point(k + 1, s + 1)]; // LEFT TOP
          profits[0][sum][Point(i, j)]++;

          result += profits[1][sum][Point(k + 1, j - 1)]; // RIGHT TOP
          profits[1][sum][Point(i, s)]++;

          result += profits[2][sum][Point(i - 1, s + 1)]; // LEFT BOTTOM
          profits[2][sum][Point(k, j)]++;

          result += profits[3][sum][Point(i - 1, j - 1)]; // RIGHT BOTTOM
          profits[3][sum][Point(k, s)]++;
        }
      }
    }
  }

  printf("%d\n", result);

  return 0;
}

