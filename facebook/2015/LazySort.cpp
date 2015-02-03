#include <cstdio>

using namespace std;

int N;
int pile[50000];

int main() {
	int T;
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", pile + i);

		int m = pile[0] - 1; int l = 1;
		int M = pile[0] + 1; int r = N - 1;

		for(int i = 1; i < N; i++) {
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

		printf("Case #%d: %s\n", c, l > r ? "yes" : "no");
	}
	return 0;
}

