#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, n, m;

int nVector[101];
int mVector[101];
int dp[101][101][2];

int solve(int nIdx, int mIdx, int op)
{
	if(nIdx > n && mIdx > m) return 0;

	int& ret = dp[nIdx][mIdx][op];
	if(ret != -1) return ret;

	ret = 0;

	int prev = op ? nVector[nIdx] : mVector[mIdx];
	bool always = op ? nIdx == 0 : mIdx == 0;
	for(int i = max(1, nIdx); i <= n; i++)
	{
		if(always || nVector[i] > prev) 
		{
			ret = max(ret, 1+solve(i, mIdx, 1));
		}
	}
	
	for(int i = max(1, mIdx); i <= m; i++)
	{
		if(always || mVector[i] > prev) 
		{
			ret = max(ret, 1+solve(nIdx, i, 0));
		}
	}

	return ret;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", nVector+i);
		for(int i = 1; i <= n; i++) scanf("%d", mVector+i);
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", max(solve(0, 0, 0), solve(0, 0, 1)));
	}

	return 0;
}

