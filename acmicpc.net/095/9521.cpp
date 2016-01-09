/**
 * 풀이 & 체점데이터로 돌려보며 품
 *  그래프로 어떤 이미지와 겹치면 안되는지는 알 수 있는데,
 *  만약 cycle이 없을경우 색의 가짓수는 K * (K - 1)^(len - 1) 이 됨
 *
 *  만약 cycle이 있을경우, cycle의 색의 가짓수를 P(n) 이라고 하면 P(n) = K * (K - 1)^(len - 1) - P(n - 1)
 *  이 되는데, 왜냐하면 첫번째 노드와 마지막 노드가 같은 색인 경우를 빼야하기 때문에 위와 같이 재귀적으로 정의할 수 있음.
 * 
 *  나머지를 구해야 하는 값이 1000000007 로 int와 혼용하여 사용하면 integer overflow가 발생하기 쉬운 문제
 *  재귀로 구현하고 가장 긴 line이 있을 경우 스택이 터질 수 있는데 다행히 그렇게 큰 입력은 주어지지 않는듯..
 *
 * 오답 노트
 *  K를 int로 읽어서 circle함수의 K * (K - 1) 이 integer overflow가 발생함
 *  circle의 길이가 1인 경우에 대한 처리가 안되어 있었음 (자기 자신과 색이 다르다는 입력이 들어올줄이야..)
 */
#include <cstdio>
#include <cstring>

using namespace std;

const int SIZE = 1000001;
const long long MOD = 1000000007;
int N, K;
int used[SIZE];
int diffColor[SIZE];
long long cache[SIZE];
int counter = 1;

long long line(int len) {
	if (len < 1) return 1;

	long long& result = cache[len];
	if (result != -1) return result;

	return result = ((K - 1) * line(len - 1)) % MOD;
}

long long circle(int len) {
	if (len == 1) return K;
	if (len == 2) return (K * 1LL * (K - 1)) % MOD;

	return (MOD + K * line(len - 1) - circle(len - 1)) % MOD;
}

long long getColoring(int idx) {
	long long result = 1;

	int startCounter = counter;
	int here = idx;
	for (;;) {
		if (used[here]) {
			if (startCounter <= used[here]) {// detected Circle
				int circleLength = counter - used[here];
				int lineLength = used[here] - startCounter;
				return (circle(circleLength) * line(lineLength)) % MOD;
			}
			else {
				return line(counter - startCounter) % MOD;
			}
		}
		used[here] = counter++;
		here = diffColor[here];
	}

	return K;
}

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		int diff;
		scanf("%d", &diff);
		diffColor[i] = diff;
	}

	memset(cache, -1, sizeof(cache));
	long long result = 1;
	for (int i = 1; i <= N; i++) {
		if (used[i]) continue;
		result *= getColoring(i);
		result %= MOD;
	}

	printf("%lld\n", result);
	return 0;
}