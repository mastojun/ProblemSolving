/**
 * 타일링 채우기는 f(n) = f(n - 1) + f(n - 2) 로 풀 수 있으며,
 * 대칭이 되기 위해서는 n/2 만큼의 타일이 생기는 경우의수만큼 빼면됨 (단, 짝수일경우 1개씩 빼도 되므로 - 2x1로 상하에 배치하면되므로 -  n/2-1 도 구해서 뺌)
 *
 * 1000000007 로 나눈 나머지를 구해야 하므로 뺄때는 이 값을 + 해서 빼둠
 */
#include <cstdio>
#include <cstring>

using namespace std;

int C;
int n;
long long dp[101];

const int MOD = 1000000007;

long long solve(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;

	long long& ret = dp[n];
	if (ret != -1) return ret;

	return ret = (solve(n - 1) + solve(n - 2)) % MOD;
}

int main() {
	scanf("%d", &C);

	memset(dp, -1, sizeof(dp));
	while (C --> 0) {
		scanf("%d", &n);

		printf("%lld\n", (solve(n) + MOD - solve(n / 2) + MOD - (n % 2 ? 0 : solve(n / 2 - 1))) % MOD);
	}

	return 0;
}

