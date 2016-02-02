#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

const int MOD = 20090711;

int solve(int N, int a, int b) {
  priority_queue<int> smaller;
  priority_queue<int, vector<int>, std::greater<int>> larger;

  int num = 1983;
  int result = 0;

  for (int i = 0; i < N; i++) {
    if (smaller.size() == 0 || smaller.top() >= num) smaller.push(num);
    else if (larger.size() == 0 || larger.top() <= num) larger.push(num);
    else smaller.push(num);

    while (smaller.size() > larger.size() + 1) {
      larger.push(smaller.top());
      smaller.pop();
    }

    while (smaller.size() < larger.size()) {
      smaller.push(larger.top());
      larger.pop();
    }

    num = (num * 1LL * a % MOD + b) % MOD;

    result += smaller.top();
    result %= MOD;
  }

  return result;
}

int main() {
  int C;
  scanf("%d", &C);

  while (C --> 0) {
    int N;
    int a, b;
    scanf("%d %d %d", &N, &a, &b);

    printf("%d\n", solve(N, a, b));

  }

  return 0;
}

