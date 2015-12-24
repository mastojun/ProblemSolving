#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n, m;
int candy[301];
int leftDp[302][302];
int rightDp[302][302];

int right(int l, int r, int remain);

int left(int l, int r, int remain) {
	if (remain == 0) return 0;

	int& result = leftDp[l + 1][r];
	if (result != -1) return result;
	result = INT_MAX;
	if (l > 0) {
		result = remain * (candy[l] - candy[l - 1]) + left(l - 1, r, remain - 1);
	}
	if (r <= n) {
		result = min(result, remain * (candy[r] - candy[l]) + right(l - 1, r, remain - 1));
	}

	return result;
}

int right(int l, int r, int remain) {
	if (remain == 0) return 0;

	int& result = rightDp[l + 1][r];
	if (result != -1) return result;
	result = INT_MAX;
	if (r < n) {
		result = remain * (candy[r + 1] - candy[r]) + right(l, r + 1, remain - 1);
	}
	if (l >= 0) {
		result = min(result, remain * (candy[r] - candy[l]) + left(l, r + 1, remain - 1));
	}

	return result;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", candy + i);
	}

	candy[n] = 0;

	sort(candy, candy + n + 1);

	int zeroIndex = 0;
	for (int i = 0; i <= n; i++) {
		if (candy[i] == 0) {
			zeroIndex = i;
			break;
		}
	}
	int result = 0;
	for (int i = 0; i <= n; i++) {
		memset(leftDp, -1, sizeof(leftDp));
		memset(rightDp, -1, sizeof(rightDp));
		result = max(result, m * i - left(zeroIndex, zeroIndex + 1, i));
	}
	printf("%d\n", result);

	return 0;
}


