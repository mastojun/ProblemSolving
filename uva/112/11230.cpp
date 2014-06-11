#include <cstdio>

using namespace std;

int main()
{
	int n, m, r, c;
	char picture[100][101];

	while(scanf("%d %d %d %d", &n, &m, &r, &c) && n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%s", picture[i]);
		}

		int result = 0;
		for(int i = 0; i <= n-r; i++)
		{
			for(int j = 0; j <= m-c; j++)
			{
				if(picture[i][j] == '1')
				{
					for(int ii = 0; ii < r; ii++)
					{
						for(int jj = 0; jj < c; jj++)
						{
							picture[i+ii][j+jj] = picture[i+ii][j+jj] == '1' ? '0' : '1';
						}
					}
					result++;
				}
			}
			for(int j = m-c+1; j < m; j++)
			{
				if(picture[i][j] == '1') result = -1;
			}
			if(result == -1) break;
		}
		for(int i = n-r+1; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(picture[i][j] == '1') result = -1;
			}
		}

		if(result == -1) puts("-1");
		else printf("%d\n", result);

	}

	return 0;
}

