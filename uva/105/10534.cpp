#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int nums[10000];
int is[10000];
int ds[10000];

int stack[10000];

int top = 0;

int lis_init() {
	top = 0;
}

int lis(int num) {
	int result = 0;
	if(top == 0 || stack[top-1] < num) {
		stack[top++] = num;
		result = top;
	} else {

		int left = 0, right = top - 1;

		while(left < right) {
			int mid = (left + right) / 2;
			if(stack[mid] < num) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}

		stack[left] = min(stack[left], num);
		result = left + 1;
	}

	return result;
}

int main() {
	while(scanf("%d", &N) == 1) {

		for(int i = 0; i < N; i++) {
			scanf("%d", nums + i);
		}

		lis_init();
		for(int i = 0; i < N; i++) {
			is[i] = lis(nums[i]);
		}

		lis_init();
		for(int i = N-1; i >= 0; i--) {
			ds[i] = lis(nums[i]);
		}

		int result = 0;
		for(int i = 0; i < N; i++) {
			result = max(result, min(is[i], ds[i]));
		}

		printf("%d\n", result * 2 - 1);
	}

	return 0;
}


