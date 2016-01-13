/**
 * union-find 문제
 *
 * fight가 있을때 서로가 같은 팀이 아니어야 하고 (같은팀이면 끝)
 * 그렇지 않다면, 상대팀의 적과 내가 같은 팀이되고, 나의 적과 상대가 같은 팀이 되어야하며,
 * 서로 적이 된다.
 *
 */
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

class Fights {
public:
  Fights(int size) {
    teams = vector<int>(size + 1);
    enermy = vector<int>(size + 1);
    height = vector<int>(size + 1);

    for (int i = 1; i <= size; i++) {
      teams[i] = i;
    }
  }

  bool sameTeam(int l, int r) {
    return root(l) == root(r);
  }

  int getEnermy(int m) {
    return root(enermy[m]);
  }

  void setEnermy(int l, int e) {
    if (enermy[l]) {
      join(enermy[l], e);
    }
    else {
      enermy[l] = e;
    }

    if (enermy[e]) {
      join(enermy[e], l);
    }
    else {
      enermy[e] = l;
    }
  }

  void join(int l, int r) {
    int lRoot = root(l);
    int rRoot = root(r);
    if (lRoot == rRoot) {
      return;
    }
    if (height[lRoot] > height[rRoot]) {
      teams[rRoot] = lRoot;
    }
    else if (height[lRoot] < height[rRoot]) {
      teams[lRoot] = rRoot;
    }
    else {
      teams[lRoot] = rRoot;
      height[lRoot]++;
    }
  }

private:
  vector<int> teams;
  vector<int> height;
  vector<int> enermy;

  int root(int n) {
    if (teams[n] == n) return n;

    return teams[n] = root(teams[n]);
  }
};


int N;
int M;

int main() {
  scanf("%d", &N);
  scanf("%d", &M);

  Fights fights(N);
  int result = 1;
  for (; result <= M; result++) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (fights.sameTeam(l, r)) {
      break;
    }
    int lEnermy = fights.getEnermy(l);
    int rEnermy = fights.getEnermy(r);
    if (rEnermy) fights.join(l, rEnermy);
    if (lEnermy) fights.join(r, lEnermy);

    fights.setEnermy(l, r);
  }

  printf("%d\n", result);

  return 0;
}

