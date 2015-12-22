/**
 * 마지막 멀티탭를 제외하고는 모든 멀티탭은
 * 다음 멀티탭을 위해 플러그 하나를 사용해야하므로 - 1을 해줘야함
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int result = 0;
	while (n --> 0) {
		int plug;
		scanf("%d", &plug);
		result += plug - (n ? 1 : 0);
	}

	printf("%d\n", result);
}

