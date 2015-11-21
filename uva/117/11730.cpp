/**
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2830
 * bfs + prime number
 */

#include <cstdio>
#include <queue>

using namespace std;

int s, t;
vector<int> primes;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void makePrimes() {
	for (int i = 2; i < 1000; i++) {
		if (isPrime(i)) primes.push_back(i);
	}
}

vector<int> getPrimeFactors(int n) {
	vector<int> result;
	for (auto i : primes) {
		if (i >= n) break;
		if (n % i == 0) result.push_back(i);
	}

	return result;
}

int solve() {
	if (s == t) return 0;

	queue<int> q;
	q.push(s);

	vector<bool> used(1001, false);
	used[s] = true;

	int result = 1;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int num = q.front(); q.pop();
			vector<int> primeFactors = getPrimeFactors(num);
			for (auto p : primeFactors) {
				int next = p + num;
				if (next >= used.size() || used[next]) continue;
				if (next == t) return result;
				q.push(next);
				used[next] = true;
			}
		}
		result++;
	}
	return -1;
}

int main() {
	makePrimes();
	int c = 1;
	while (scanf("%d %d", &s, &t) == 2) {
		if (s == 0 && t == 0) break;
		printf("Case %d: %d\n", c++, solve());
	}
	return 0;
}

