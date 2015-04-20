#include <cstdio>

using namespace std;

int T;
int N;
int B;
int M[1000];

void input() {
	scanf("%d %d", &B, &N);
	for(int i = 0; i < B; i++) {
		scanf("%d", M + i);
	}
}

bool needMoreTime(long long mid) {
	long long nth = 0;
	for(int i = 0; i < B; i++) {
		nth += mid / M[i] + 1;
	}
	return nth < N;
}

int getWorkThatTimeBarber(long long time) {
	for(int i = 0; i < B; i++) {
		if(time % M[i] == 0) {
			N -= time / M[i];
		} else {
			N -= time / M[i] + 1;
		}
	}

	for(int i = 0; i < B; i++) {
		if(time % M[i] == 0) {
			N--;
			if(N <= 0) return i + 1;
		}
	}

	return -1;
}

int solve() {
	long long left = 0;
	long long right = 1000000000000000LL;

	while(left < right) {
		long long mid = (left + right) / 2;

		if(needMoreTime(mid)) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	return getWorkThatTimeBarber(left);
}

int main() {

	scanf("%d", &T);

	for(int Case = 1; Case <= T; Case++) {
		input();
		printf("Case #%d: %d\n", Case, solve());
	}

	return 0;
}

