/**
 * solve(n, m, idx) = idx == 1이면 vm[m]이 끝인 jlis구하기, 0이면 vm[n]이 끝인 jlis 구하기
 * 위 연산을 n을 0~n-1, m을 0~m-1 에 대해서 모두 구하고 가장 큰 값을 구함
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int C;
vector<int> vn;
vector<int> vm;
int dp[100][100][2];

int solve(int n, int m, int idx) {
	int& result = dp[n][m][idx];
	if (result != -1) return result;

	result = 1;

	int prevNum = idx == 1 ? vm[m] : vn[n];

	for (int i = n - (idx == 0); i >= 0; i--) {
		if (vn[i] < prevNum) result = max(result, 1 + solve(i, m, 0));
	}
	for (int i = m - (idx == 1); i >= 0; i--) {
		if (vm[i] < prevNum) result = max(result, 1 + solve(n, i, 1));
	}

	return result;
}

int main() {
	scanf("%d", &C);

	while (C --> 0) {
		int n, m;
		scanf("%d %d", &n, &m);

		vn.clear();
		vm.clear();
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			vn.push_back(num);
		}

		for (int i = 0; i < m; i++) {
			int num;
			scanf("%d", &num);
			vm.push_back(num);
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result = max(result, max(solve(i, j, 0), solve(i, j, 1)));
			}
		}

		printf("%d\n", result);

	}

	return 0;
}
