#include <cstdio>

#include <iostream>

#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

double solve(int n, vector<vector<pair<int, double>>>& nodes) {
  priority_queue<pair<double, int>> pq;
  vector<double> dist(n, numeric_limits<double>::max());

  pq.push(make_pair(-1, 0));

  while (!pq.empty()) {
    double amp = -pq.top().first;
    int here = pq.top().second;
    pq.pop();

    if (dist[here] <= amp) {
      continue;
    }
    dist[here] = amp;
    for (auto next : nodes[here]) {
      int nextPoint = next.first;
      double nextAmp = amp * next.second;
      if (dist[nextPoint] > nextAmp) {
        pq.push(make_pair(-nextAmp, nextPoint));
      }
    }
  }

  return dist[n - 1];
}

int main() {
  int C;
  scanf("%d", &C);

  while (C --> 0) {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<pair<int, double>>> nodes(N);
    for (int i = 0; i < M; i++) {
      int from, to;
      double amp;
      scanf("%d %d %lf", &from, &to, &amp);
      nodes[from].push_back(make_pair(to, amp));
      nodes[to].push_back(make_pair(from, amp));
    }

    printf("%.10lf\n", solve(N, nodes));
  }

  return 0;
}

