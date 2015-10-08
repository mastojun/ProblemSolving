#include <stdio.h>

#define ABS(N) ((N)<0?-(N):(N))
int main()
{
	long long N, M;

	scanf("%lld %lld", &N, &M);

	printf("%lld\n", ABS(N-M));
	return 0;
}


