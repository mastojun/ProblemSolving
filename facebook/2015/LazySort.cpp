#include <cstdio>

using namespace std;

int N;
int pile[50000];

bool canSolve(int l, int r, int m, int M) {
	while(l <= r) {
		if(m == pile[l]) {
			m--;
			l++;
		} else if(m == pile[r]) {
			m--;
			r--;
		} else if(M == pile[l]) {
			M++;
			l++;
		} else if(M == pile[r]) {
			M++;
			r--;
		} else break;

	}

	return l > r;
}

int main() {
	int T;
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", pile + i);


		printf("Case #%d: %s\n", c, canSolve(1, N - 1, pile[0] - 1, pile[0] + 1) || canSolve(0, N - 2, pile[N-1] - 1, pile[N-1] + 1) ? "yes" : "no");
	}
	return 0;
}

