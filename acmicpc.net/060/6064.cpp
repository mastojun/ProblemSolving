#include <cstdio>

using namespace std;

int T, M, N, x, y;

int gcd(int M, int N) {
	if(M == 0) return N;
	return gcd(N%M, M);
}

int main() {
	scanf("%d", &T);

	while(T --> 0){
		scanf("%d %d %d %d", &M, &N, &x, &y);

		int maximum = M * N / gcd(M, N);
		int result, i;
		for(i = 0, result = x; result <= maximum; i++, result = M*i + x) {
			if(result % N == y % N) {
				break;
			}
		}

		printf("%d\n", result <= maximum ? result : -1);
	}

	return 0;
}

