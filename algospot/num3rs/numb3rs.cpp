#include <cstdio>

using namespace std;

int c;
int n, d, p;
int t, q;
int town[50][50];
int counter[50];
double dp[51][101];

double solve(int q, int d)
{
	if(d == 0)
	{
		if(q == p) return 1.;
		return 0.;
	}

	double& ret = dp[q][d];
	if(ret != -1.) return ret;

	ret = 0.;

	for(int i = 0; i < n; i++)
	{
		if(town[q][i] == 1)
		{
			ret += solve(i, d-1)*1./counter[i];
		}
	}

	return ret;
}


int main()
{
	scanf("%d", &c);
	while(c --> 0)
	{
		scanf("%d %d %d", &n, &d, &p);

		for(int i = 0; i < n; i++)
		{
			counter[i] = 0;
			for(int j = 0; j < n; j++)
			{
				scanf("%d", town[i]+j);
				counter[i] += town[i][j];
			}
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= d; j++)
			{
				dp[i][j] = -1;
			}
		}

		scanf("%d", &t);
		while(t --> 0)
		{
			scanf("%d", &q);
			printf("%.8lf %c", solve(q, d), t ? ' ' : '\n');
		}
	}

	return 0;
}

