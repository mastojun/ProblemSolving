/*
* 문제에 주어진 조건을 잘 보면, 약수중 가장 큰 수를 구해서 N에서 빼면됨
*/
#include <iostream>
using namespace std;

int solve(int N) {
	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0) return N / i;
	}

	return 1;
}
int main() {
	int N;
	cin >> N;

	cout << N - solve(N) << endl;

	return 0;
}

