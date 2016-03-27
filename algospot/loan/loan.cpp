/**
 * 2분법으로 풀 수 있는 문제
 *
 * 오답노트 : 최대값을 N으로 했었는데, 이율이 P이고 1개월 만에 갚아야 하는 경우 N보다 더 많은 돈이 필요하다. 이 경우를 생각을 떠올리는데 오래걸림.
 */

#include <cstdio>

using namespace std;

int T;
double N;
int M;
double P;

bool canPayback(double money) {
  double remain = N;
  for (int i = 0; i < M; i++) {
    remain *= (1. + P/12/100);
    remain -= money;

    if(remain <= 1e-8) return true;
  }
  return false;
}


int main() {

  scanf("%d", &T);
  while (T --> 0) {
    scanf("%lf %d %lf", &N, &M, &P);

    double left = 0;
    double right = 1e12;
    while (right - left > 1e-8) {
      double mid = left + (right - left) / 2.;
      if (canPayback(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }

    printf("%.10lf\n", left);
  }

  return 0;
}

