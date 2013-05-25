#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int c, n, s;
int arr[100];

int dp[100][11];

int avg(int s, int e)
{
	int sum = 0;
	for(int i = s; i <= e; i++)
	{
		sum += arr[i];
	}

	return sum*1./(e-s+1)+.5;
}

int variance(int s, int e)
{
	int a = avg(s, e);
	int v = 0;
	for(int i = s; i <= e; i++)
	{
		v += (a-arr[i])*(a-arr[i]);
	}
	return v;
}

int solve(int idx, int s)
{
	if(idx == n) return 0;
	if(s == 0) return 987654321;

	int& ret = dp[idx][s];
	if(ret != -1) return ret;

	ret = 987654321;
	for(int i = idx; i < n; i++)
	{
		ret = min(ret, variance(idx, i) + solve(i+1, s-1));
	}

	return ret;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		scanf("%d %d", &n, &s);

		for(int i = 0; i < n; i++)
		{
			scanf("%d", arr+i);
		}

		sort(arr, arr+n);
		memset(dp, -1, sizeof(dp));

		printf("%d\n", solve(0, s));

	}

	return 0;
}

