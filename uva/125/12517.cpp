#include <cstdio>

using namespace std;

long long digitSum(int n) {
	long long result = 0;

	int pow = 1;
	int pre = n;

	while(pre) {
		int num = pre%10;
		pre /= 10;

		for(int i = 1; i < 10; i++) {
			result += i * pre * pow;

			if(num == i) {
				result += i * (n%pow + 1);
			} else if(i < num) {
				result += i * pow;
			}
		}

		pow *= 10;
	}

	return result;
}

int main() {
	int M, N;

	while(scanf("%d %d", &M, &N) == 2) {
		if(M == 0 && N ==0) break;

		printf("%lld\n", digitSum(N) - digitSum(M-1));
	}

	return 0;
}

