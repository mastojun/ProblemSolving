#include <cstdio>
#include <cstring>

using namespace std;

int T;
int N, M;

int matrix[501][501];
long long ct[3][501];

long long fourGods(int start)
{
	memset(ct, 0, sizeof(ct));

	ct[0][start] = 1;

	for(int i = 1; i <= 2; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(ct[i-1][j] != 0)
				for(int k = 1; k <= N; k++)
				{
					if(matrix[j][k] == 1 && k != start)
					{
						ct[i][k]+=ct[i-1][j];
					}
				}
		}
	}

	long long ret = 0;

	for(int i = start+1; i <= N; i++)
	{
		ret += ct[2][i]*(ct[2][i]-1)/2;
	}

	return ret;
}

int main()
{
	scanf("%d", &T);

	while(T --> 0)
	{
		scanf("%d %d", &N, &M);

		memset(matrix, 0, sizeof(matrix));

		for(int i = 0; i < M; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			matrix[u][v] = matrix[v][u] = 1;
		}

		long long result = 0;
		for(int i = 1; i <= N; i++)
		{
			result += fourGods(i);
		}

		printf("%lld\n", (result/2) % 20130728);

	}

	return 0;
}


