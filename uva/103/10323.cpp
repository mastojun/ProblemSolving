#include <cstdio>

using namespace std;

int main() {

	long long number = 0;
	while(scanf("%lld", &number) == 1){
		if(number < 0) number = number%2 ? 100 : 0;
		long long result = 1;
		for(;number > 1; number--) {
			result *= number;
			if(result > 6227020800) break;
		}

		if(result > 6227020800) puts("Overflow!");
		else if(result < 10000) puts("Underflow!");
		else printf("%lld\n", result);
	}
	return 0;
}

