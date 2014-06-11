#include <cstdio>

int n, m, r, c;
int picture[100][101];
int cache[100][100];

int main()
{
	while(scanf("%d %d %d %d", &n, &m, &r, &c) && n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%s", picture[i]);
		}

		memset(cache, -1, sizeof(cache));

		int result = 0;
		bool possible = false;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(isToggled(i, j) ^ (picture[i][j] == '1'))
				{
					result++;
					if(i > n-r || j > m-c)
					{
						possible = false;
					}
				}
			}
		}

		printf("%d\n", possible ? result : -1);
	}

	return 0;
}

