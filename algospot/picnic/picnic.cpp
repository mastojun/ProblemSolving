/**
 * dp로 2^n * n * n 으로 풀어보았으나
 * algospot 에서는 별 차이 안남, 로컬에서 테스트 해보니 가장 답이 큰 경우엔 4배정도 차이남.
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
int T;
int n, m;
vector<vector<bool>> pairs;

int dp[1025][10];

bool isSet(int idx, int pos) {
	return (idx >> pos) & 1;
}

void set(int& idx, int pos) {
	idx |= 1 << pos;
}

void off(int& idx, int pos) {
	idx &= ~(1 << pos);
}

int solve(int& used, int idx) {
	if (idx >= n) return 1;
	if (isSet(used, idx)) return solve(used, idx + 1);

	int& result = dp[used][idx];
	if (result != -1) return result;

	set(used, idx);
	result = 0;
	for (int i = idx + 1; i < n; i++) {
		if (isSet(used, i)) continue;
		if (!pairs[idx][i]) continue;
		set(used, i);
		result += solve(used, idx + 1);
		off(used, i);
	}

	off(used, idx);
	return result;
}
int main() {
	scanf("%d", &T);

	while (T --> 0) {
		scanf("%d %d", &n, &m);

		pairs = vector<vector<bool>>(n, vector<bool>(n, 0));

		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			pairs[b][a] = pairs[a][b] = 1;
		}
		int used = 0;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(used, 0));
	}

	return 0;
}
