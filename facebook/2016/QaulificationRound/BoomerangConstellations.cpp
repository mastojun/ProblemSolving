#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int T;
int N;
struct Point {
  int x, y;

  int distSquare(const Point& other) {
    return (x - other.x) * (x - other.x)
          + (y - other.y) * (y - other.y);
  }

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }

  bool operator<(const Point& other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }

} point[10000];


map<int, map<Point, int>> distPoints;

int insert(Point& from, Point& to) {
  int distSquare = from.distSquare(to);
  int result = 0;
  result += distPoints[distSquare][from]++;
  result += distPoints[distSquare][to]++;

  return result;
}

int main() {
  scanf("%d", &T);
  for (int c = 1; c <= T; c++) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
      scanf("%d %d", &point[i].x, &point[i].y);
    }

    distPoints.clear();

    int result = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        result += insert(point[i], point[j]);
      }
    }

    printf("Case #%d: %d\n", c, result);
  }

  return 0;
}

