/**
 * 이분법이 아닌 수식으로 품
 */
#include <cstdio>
#include <cmath>

using namespace std;

int T;
double N;
int M;
double P;

int main() {

  scanf("%d", &T);
  while (T --> 0) {
    scanf("%lf %d %lf", &N, &M, &P);

    P = 1 + P/12/100;

    double NxPM = N * pow(P, M);
    double Ps = 0;
    for (int i = 0; i < M; i++) {
      Ps += pow(P, i);
    }

    printf("%.10lf\n", NxPM / Ps);
  }

  return 0;
}

