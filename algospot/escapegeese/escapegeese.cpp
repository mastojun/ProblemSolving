#include <cstdio>
#include <cstring>

#define MOD 1000000007

using namespace std;

int T, N, K;
int cache[500][100];

int solve(int mod, int escape)
{
	if(escape == K) return mod == 0;
	if(idx >= N) return 0;

	int& r = cache[mod][idx][escape];
	if(r != -1) return r;

	r = (solve(mod, idx+1, escape) + solve((mod+idx)%N, idx+1, escape+1)) % MOD;

	return r;
}

int main()
{
	scanf("%d", &T);

	while(T --> 0)
	{
		scanf("%d %d", &N, &K);
		memset(cache, -1, sizeof(cache));

		printf("%d\n", solve(0, 0, 0));
	}

	return 0;
}

