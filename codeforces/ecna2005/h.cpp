/**
 * 풀이
 * first player는 양쪽중 어느것이나 선택할 수 있으며, second는 first가 선택하고 나서 나머지값중 가장 큰 값을 선택을 하므로
 * 조건대로 시뮬레이션을 수행함.
 * 단, left, right조합이 많으므로 메모이제이션 적용
 */

#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> cards;
int dp[1000][1000];

int solve(int left, int right) {
	if (left > right) return 0;

	int& result = dp[left][right];
	if (result != -1) return result;

	result = 0;
	if (cards[left + 1] >= cards[right]) {
		result = max(result, cards[left] - cards[left + 1] + solve(left + 2, right));
	}
	else {
		result = max(result, cards[left] - cards[right] + solve(left + 1, right - 1));
	}
	if (cards[left] >= cards[right - 1]) {
		result = max(result, cards[right] - cards[left] + solve(left + 1, right - 1));
	}
	else {
		result = max(result, cards[right] - cards[right - 1] + solve(left, right - 2));
	}
	return result;
}

int solve() {
	return solve(0, cards.size() - 1);
}

int main() {
	int game = 1;

	int n;

	while (scanf("%d", &n)) {
		if (n == 0) break;

		cards.clear();
		for (int i = 0; i < n; i++) {
			int c;
			scanf("%d", &c);
			cards.push_back(c);
		}

		memset(dp, -1, sizeof(dp));

		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", game++, solve());
	}
}


