/**
 * 보석을 가치의 내림 차순으로 정렬 후
 * 가장 값어치가 높은 보석부터, 들어갈 수 있는 가장 작은 가방에 들어감
 * stl set 에 lower_bound 로 해결 (...)
 * O(N log N + N log K + K log K) (.... 이런건 어떻게 표현한데..)
 *
 * 오답 노트
 *  N max가 300000 이고 하나의 V max가 1000000 이므로 64bit integer를 사용해야 했...
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;


struct Gem {
  int M, V;
};
int N, K;
Gem gems[300000];
multiset<int> bags;

bool orderByValueDesc(const Gem& l, const Gem& r) {
  return l.V > r.V;
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &gems[i].M, &gems[i].V);
  }
  for (int i = 0; i < K; i++) {
    int bag;
    scanf("%d", &bag);
    bags.insert(bag);
  }

  sort(gems, gems + N, orderByValueDesc);

  int result = 0;
  for (auto gem : gems) {
    auto bag = bags.lower_bound(gem.M);
    if (bag != bags.end()) {
      bags.erase(bag);
      result += gem.V;
    }
  }

  printf("%d\n", result);
  return 0;
}

