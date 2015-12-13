/**
 * 숫자가 21개, 총 10개, 최대가능성은 21P10 으로 엄청 클줄 알았지만..
 * 각 자리에 들어가는 수는 0, 양수, 음수 중 하나이므로 아무리 커봐야 10!.. 이지만 이마져도 커서 안될꺼라 생각했는데
 * 숫자를 집어넣기 전에 미리미리 검사해두면 시간을 감소시킬 수 있음.
 * 속도가 더 빠른 솔루션을 보니, 숫자를 집어넣고 0 ~ idx까지 돌아 들어갈 수 있는지 검사하지 않고, 미리 들어갈 수 있는 숫자범위를 판단한후 집어넣는 방법을 취했음 (=ㅂ=)bb
 **/
#include <iostream>
#include <string>
using namespace std;

int N;
char r[10][10];
int result[10];

bool canSet(int idx, int n) {
	int sum = n;
	for (int i = idx - 1; i >= 0; i--) {
		sum += result[i];
		if (sum == 0 && r[i][idx] != '0') return false;
		if (sum < 0 && r[i][idx] != '-') return false;
		if (sum > 0 && r[i][idx] != '+') return false;
	}

	return true;
}

bool solve(int idx) {
	if (idx >= N) return true;

	int s = 0;
	int e = 0;

	if (r[idx][idx] == '+') {
		s = 1;
		e = 10;
	}
	else if (r[idx][idx] == '-') {
		s = -10;
		e = -1;
	}

	for (int i = s; i <= e; i++) {
		if (!canSet(idx, i)) continue;
		result[idx] = i;
		if (solve(idx + 1)) return true;
	}

	return false;
}

int main() {
	cin >> N;

	string str;
	cin >> str;

	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			r[i][j] = str[idx++];
		}
	}

	if(solve(0)) {
		for (int i = 0; i < N; i++) {
			cout << result[i] << ' ' << endl;
		}
	}
	else {
		cout << "I can't found" << endl;
	}

	return 0;
}

