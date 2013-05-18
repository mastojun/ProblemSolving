#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int c;
char number[10001];
int dp[10001];
int length;

bool allSame(int start, int end)
{
	for(int i = start; i < end; i++)
	{
		if(number[start] != number[i]) return false;
	}
	return true;
}

bool isMonotone(int start, int end)
{
	int gap = number[start+1] - number[start];
	if(gap != 1 && gap != -1) return false;
	for(int i = start+1; i < end; i++)
	{
		if(gap != number[i]-number[i-1]) return false;
	}
	return true;
}

bool isZigzag(int start, int end)
{
	for(int i = start+2; i < end; i++)
	{
		if(number[i] != number[i-2]) return false;
	}
	return true;
}

bool isArthmeticalProgression(int start, int end)
{
	int gap = number[start+1] - number[start];
	for(int i = start+1; i < end; i++)
	{
		if(gap != number[i]-number[i-1]) return false;
	}
	return true;
}

int score(int start, int end)
{
	if(allSame(start, end)) return 1;
	if(isMonotone(start, end)) return 2;
	if(isZigzag(start, end)) return 4;
	if(isArthmeticalProgression(start, end)) return 5;
	return 10;
}

int solve(int idx)
{
	if(idx == length){return 0;}
	if(idx+3 > length){return 987654321;}
	int& ret = dp[idx];
	if(ret != -1) return ret;

	ret = 987654321;

	for(int i = 3; i <= 5; i++)
	{
		ret = min(ret, score(idx, idx+i) + solve(idx+i));
	}

	return ret;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		scanf("%s", number);

		memset(dp, -1, sizeof(dp));
		length = strlen(number);

		printf("%d\n", solve(0));
	}

	return 0;
}

