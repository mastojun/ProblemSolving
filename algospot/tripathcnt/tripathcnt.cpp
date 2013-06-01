#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int c;
int n;
int triangle[100][100];
int priceCache[100][100];
int pathCache[100][100];

int getMaxPath(int x, int y)
{
	if(y == n) return 0;

	int& ret = priceCache[y][x];
	if(ret != -1) return ret;

	ret = triangle[y][x] + max(getMaxPath(x, y+1), getMaxPath(x+1, y+1));

	return ret;
}

int solve(int x, int y)
{
	if(y == n) return 1;

	int& ret = pathCache[y][x];
	if(ret != -1) return ret;

	int remain = getMaxPath(x, y)  - triangle[y][x];

	ret = 0;
	if(remain == 0) return ret = 1;
	if(remain == getMaxPath(x, y+1)) ret += solve(x, y+1);
	if(remain == getMaxPath(x+1, y+1)) ret += solve(x+1, y+1);

	return ret;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				scanf("%d", &triangle[i][j]);
			}
		}

		memset(priceCache, -1, sizeof(priceCache));
		memset(pathCache, -1, sizeof(pathCache));

		int maxPath = getMaxPath(0, 0);
		printf("%d\n", solve(0, 0));
	}

	return 0;
}
