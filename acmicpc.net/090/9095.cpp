/**
 * n이 11밖에 되지 않으므로 dfs로 품.
 * 크기가 더 크다면 dp로 풀면 되는 문제
 */
#include <iostream>
using namespace std;

int n;

int solve(int num) {
	if (num == n) return 1;
	if (num > n) return 0;

	return solve(num + 1) + solve(num + 2) + solve(num + 3);
}

int main() {
	int T;
	cin >> T;

	while (T --> 0) {
		cin >> n;
		cout << solve(0) << endl;
	}

	return 0;
}

