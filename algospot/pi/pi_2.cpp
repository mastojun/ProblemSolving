/**
 * 평범한 dp (?)
 * difficulty  구하는게 핵심인 부분
 * 과거엔 1씩 단조증가/감소와 등차수열을 나누어 계산했는데 이번엔 하나로 추상화했음
 * 뭐가 더 좋은진 모르겠.....
 */
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c;
string pi;
vector<int> dp;

bool isAllSame(int s, int e) {
	for (int i = s; i <= e; i++) {
		if (pi[i] != pi[s]) return false;
	}
	return true;
}

bool hasDiff(int s, int e, int diff) {
	for (int i = s + 1; i <= e; i++) {
		if (pi[i] - pi[i - 1] != diff) return false;
	}
	return true;
}

bool isZigzag(int s, int e) {
	for (int i = s; i <= e; i++) {
		if ((i - s) % 2 && pi[i] != pi[s + 1]) return false;
		else if ((i - s) % 2 == 0 && pi[i] != pi[s]) return false;
	}

	return true;
}

int difficulty(int s, int e) {
	if (s == e) return 1;
	if (isAllSame(s, e)) return 1;
	if (hasDiff(s, e, -1) || hasDiff(s, e, 1)) return 2;
	if (isZigzag(s, e)) return 4;
	if (hasDiff(s, e, pi[s + 1] - pi[s])) return 5;
	return 10;
}

int solve(int idx) {
	if (idx >= pi.length()) return 0;

	int& ret = dp[idx];
	if (ret != -1) return ret;

	ret = 987654321;

	for (int i = idx + 2; i < min((int)pi.length(), idx + 5); i++) {
		ret = min(ret, difficulty(idx, i) + solve(i + 1));
	}

	return ret;
}

int main() {
	cin >> c;

	while (c --> 0) {
		cin >> pi;
		dp = vector<int>(pi.length(), -1);
		cout << solve(0) << endl;
	}

	return 0;
}
