#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> A;
vector<int> B;

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    int n;
    scanf("%d", &n);
    A.push_back(n);
  }
  for (int i = 0; i < M; i++) {
    int n;
    scanf("%d", &n);
    B.push_back(n);
  }

  int n = 0;
  int m = 0;
  while (n != N || m != M) {
    if (n == N) {
      printf("%d ", B[m++]);
    } else if (m == M || A[n] < B[m]) {
      printf("%d ", A[n++]);
    } else {
      printf("%d ", B[m++]);
    }
  }

  return 0;
}

