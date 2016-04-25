#include <cstdio>
#include <cmath>

#include <tuple>
#include <queue>

using namespace std;

int N, M;

int xs[500];
int ys[500];

class Disjoint {
private:
  int parent[500];
  int height[500];

public:
  void init(int n) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      height[i] = 0;
    }
  }


  void merge(int l, int r) {
    int lParent = getParent(l);
    int rParent = getParent(r);

    if (lParent == rParent) return;

    int lHeight = height[l];
    int rHeight = height[r];

    if (lHeight < rHeight) {
      parent[lParent] = rParent;
    } else {
      parent[rParent] = lParent;
      height[rParent]++;
    }
  }

  int getParent(int n) {
    if (parent[n] == n) return n;

    return parent[n] = getParent(parent[n]);
  }

  bool sameParent(int l, int r) {
    return getParent(l) == getParent(r);
  }
};

double dist(int from, int to) {
  int dx = xs[from] - xs[to];
  int dy = ys[from] - ys[to];
  return sqrt(dx * dx + dy * dy);
}

int main() {
  Disjoint disjoint;
  int C;
  scanf("%d", &C);

  while (C --> 0) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
      scanf("%d", xs + i);
    }
    for (int i = 0; i < N; i++) {
      scanf("%d", ys + i);
    }

    disjoint.init(N);

    for (int i = 0; i < M; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      disjoint.merge(l, r);
    }
    priority_queue<tuple<double, int, int>> dists;

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (disjoint.sameParent(i, j)) continue;
        dists.push(make_tuple(-dist(i, j), i, j));
      }
    }

    double result = 0;
    while (!dists.empty()) {
      double dist = -get<0>(dists.top());
      int from = get<1>(dists.top());
      int to = get<2>(dists.top());
      dists.pop();
      if (disjoint.sameParent(from, to)) continue;

      result += dist;
      disjoint.merge(from, to);
    }

    printf("%.10lf\n", result);
  }

  return 0;
}

