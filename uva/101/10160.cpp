#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;

int town[40][40];
int used[40];

int result;
int r;

bool allUsed()
{
	for(int i = 1; i <= N; i++)
	{
		if(used[i] == 0) return false;
	}

	return true;
}

void solve(int i, int must)
{
	if(i > N){
		if(allUsed() && result > r){
			result = r;
		}
		return;
	}

	used[i]++;
	for(int t = 1; t <= N; t++)
	{
		if(town[i][t]) used[t]++;
	}
	r+=1;
	solve(i+1, 0);
	r-=1;

	for(int t = 1; t <= N; t++)
	{
		if(town[i][t]) used[t]--;
	}
	used[i]--;

	if(must == 0 && used[i] == 0)
	{
		for(int t = i+1; t <= N; t++)
		{
			if(town[i][t] && used[i] == 0) solve(i+1, 1);
		}
	}
}

int main()
{
	while(true)
	{
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) break;

		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				town[i][j] = 0;
			}
			used[i] = 0;
		}

		for(int i = 0; i < M; i++)
		{
			int s, e;
			scanf("%d %d", &s, &e);
			town[s][e] = town[e][s] = 1;
		}

		result = 40;
		r = 0;
		solve(1, 0);
		printf("%d\n", result);
	}

	return 0;
}


