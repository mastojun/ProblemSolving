#include <cstdio>

using namespace std;

int T;
int N, M;
int floor[6][6];

int solve(int x, int y, int order)
{
	if(x < 0 || x >= M) return 0;
	if(y < 0 || y >= N) return 0;

	if(floor[y][x] == -1 || floor[y][x] == order){
		if(x == M-1 && y == N-1) return 1;
		int old = floor[y][x];
		floor[y][x] = order;

		int result = 0;

		result = solve(x-1, y, order+1)
				+ solve(x+1, y, order+1)
				+ solve(x, y-1, order+1)
				+ solve(x, y+1, order+1);

		floor[y][x] = old;
		return result;
	}
	else return 0;
}

int main()
{
	scanf("%d", &T);
	while(T --> 0)
	{
		scanf("%d %d", &N, &M);

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				scanf("%d", &floor[i][j]);
			}
		}

		printf("%d\n", solve(0, 0, 0));
	}

	return 0;
}

