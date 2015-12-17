/**
 * 누구 차례가 되든 같은 전략을 취하면 되기 때문에
 * 선택 가능한 4가지 옵션중에서 항상 최선의 선택을 하며, 상대방이 선택한건 차이가 적어지므로 - 를 달아줌
 */
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int C;
int n;
int nums[50];

int dp[50][50];

int solve(int s, int e) {
	if (s > e) return 0;

	int& result = dp[s][e];
	if (result != -987654321) return result;

	result = nums[s] - solve(s + 1, e);
	result = max(result, nums[e] - solve(s, e - 1));
	if (e - s >= 2) {
		result = max(result, -solve(s + 2, e));
		result = max(result, -solve(s, e - 2));
	}

	return result;
}

int main() {

	scanf("%d", &C);
	while (C-- > 0) {
		scanf("%d", &n);
		int total = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", nums + i);
			total += nums[i];
			for (int j = 0; j < n; j++) {
				dp[i][j] = -987654321;
			}
		}

		printf("%d\n", solve(0, n - 1));
	}

	return 0;
}

