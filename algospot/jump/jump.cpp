#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	while(T --> 0)
	{
		long long K;
		scanf("%lld", &K);

		K = K*(K+1)/2+1;

		printf("%lld\n", K*K%20130728);
	}

	return 0;
}

