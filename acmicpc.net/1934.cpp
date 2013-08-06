#include <stdio.h>

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int N, a, b;
	scanf("%d", &N);

	while(N --> 0)
	{
		scanf("%d %d", &a, &b);

		int g = gcd(a, b);

		printf("%d\n", a*b/g);
	}

	return 0;
}

