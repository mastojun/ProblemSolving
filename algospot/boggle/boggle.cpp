#include <cstdio>
#include <cstring>
#include <vector>

int c;
int cache[11][5][5];
char boggle[5][6];
char inputString[11];
int n;

bool getResult(int idx, int y, int x)
{
	if(inputString[idx] == 0) return true;
	if(y < 0 || 5 <= y) return false;
	if(x < 0 || 5 <= x) return false;

	int& ret = cache[idx][y][x];

	if(ret != -1) return ret;

	ret = false;

	if(boggle[y][x] == inputString[idx])
	{
		ret = getResult(idx+1, y-1, x)
			|| getResult(idx+1, y+1, x)
			|| getResult(idx+1, y, x+1)
			|| getResult(idx+1, y, x-1)
			|| getResult(idx+1, y-1, x-1)
			|| getResult(idx+1, y-1, x+1)
			|| getResult(idx+1, y+1, x-1)
			|| getResult(idx+1, y+1, x+1);
	}

	return ret;
}

bool getResult()
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(getResult(0, i, j)) return true;
		}
	}

	return false;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		for(int i = 0; i < 5; i++)
		{
			scanf("%s", boggle[i]);
		}

		scanf("%d", &n);
		while(n --> 0)
		{
			scanf("%s", inputString);
			memset(cache, -1, sizeof(cache));
			printf("%s %s\n", inputString, getResult()?"YES":"NO");
		}
	}

	return 0;
}
