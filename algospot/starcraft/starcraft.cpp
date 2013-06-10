#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double nCr(int n, int r)
{
	double result = 1.;
	for(int i = 1; i <= r; i++)
	{
		result *= (n-i);
		result /= i;
	}

	return result;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T --> 0)
	{
		int P, K;
		scanf("%d %d", &P, &K);

		double result = 0;
		for(int i = 0; i < K; i++)
		{
			result += pow(P/100., K) * pow((100-P)/100., i) * nCr(K+i, i);
		}

		printf("%.0lf\n", result*100);
	}

	return 0;
}

