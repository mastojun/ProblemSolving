#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MOD 10000000

int c, n;
int cache[101][101];

int solve(int n, int size)
{
	if(n <= 0) return 1;
	if(n-size == 0) return 1;

	int& ret = cache[n][size];
	if(ret != -1) return ret;

	ret = 0;
	int remainSize = n-size;
	for(int i = 1; i <= remainSize; i++)
	{
		ret += (abs(size+i)-1) * solve(remainSize, i);
		ret %= MOD;
	}

	return ret;
}

int solve(int n)
{
	int result = 0;
	for(int i = 1; i <= n; i++)
	{
		result += solve(n, i);
		result %= MOD;
	}

	return result;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		scanf("%d", &n);

		memset(cache, -1, sizeof(cache));

		printf("%d\n", solve(n));
	}

	return 0;
}

