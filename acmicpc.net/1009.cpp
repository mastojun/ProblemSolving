#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	while(T --> 0)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		int result = 1;

		for(int i = 0; i < b; i++)
		{
			result *= a;
			result %= 10;
		}

		printf("%d\n", result ? result : 10);
	}

	return 0;
}

