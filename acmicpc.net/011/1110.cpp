#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	int now = N;
	int result = 0;

	for(;now != N || result == 0; result++)
	{
		now = (now%10*10) + (now/10+now%10)%10;
	}

	printf("%d", result);

	return 0;
}

