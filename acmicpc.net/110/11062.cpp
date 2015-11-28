/**
 * url : https://www.acmicpc.net/problem/11062
 * dp 문제
 * 두명이 번갈아 가면서 모두 최적의 해를 구하기 때문에 누구의 턴이냐에 따라 동작을 다르게 해야함.
 * 점수를 구하는 사람의 턴에서는 가장 많은 점수를 얻을 수 있는 전략으로, 상대방의 턴에서는 상대의 점수를 작게 구하는 전략으로 구현을함
 *
 * 재귀로 구현했으며 그냥 구현하면 2^N 이 되기 때문에 dp를 사용하여 N^2로 만듬
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

using namespace std;

int T;
int N;
int cards[1000];
int dp[1000][1000][2];

int cardSelect(int s, int e, int t) {
	if (s > e) return 0;

	int& result = dp[s][e][t];
	if (result != -1) return result;

	result = 0;

	if (t == 1) {
		result = cards[s] + cardSelect(s + 1, e, !t);
		result = max(result, cards[e] + cardSelect(s, e - 1, !t));
	}
	else {
		result = cardSelect(s + 1, e, !t);
		result = min(result, cardSelect(s, e - 1, !t));
	}

	return result;
}

int main() {
	scanf("%d", &T);

	while (T --> 0) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", cards + i);
		}

		memset(dp, -1, sizeof(dp));
		printf("%d\n", cardSelect(0, N - 1, 1));
	}

	return 0;
}

