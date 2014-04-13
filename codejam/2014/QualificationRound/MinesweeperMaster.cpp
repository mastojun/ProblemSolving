#include <cstdio>
#include <queue>

using namespace std;

int T;
int R, C, M;
int zeroCount;
char mines[50][50];

bool solve()
{
	int remain = R*C-M;
	if(remain < 4) return false;

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			mines[i][j] = '*';
		}
	}
	int right = 2;
	int down = 2;
	remain -= 4;

	while(remain) {
		if(remain == 1) {
			if(down == 2 || right == 2) return false;
			break;
		}else{
			if(right <= down && right < C) right++;
			else if(down < R) down++;
			else if(right < C) right++;
			else {
				break;
			}
			remain-=2;
		}
	}

	for(int i = 0; i < right; i++)
		mines[0][i] = mines[1][i] = '.';
	for(int i = 0; i < down; i++)
		mines[i][0] = mines[i][1] = '.';

	for(int i = 2; i < right; i++)
		for(int j = 2; j < down; j++)
		{
			if(remain > 0) mines[j][i] = '.';
			remain--;
		}
	return true;
}

int main()
{
	scanf("%d", &T);
	for(int Case = 1; Case <= T; Case++)
	{
		printf("Case #%d:\n", Case);
		scanf("%d %d %d", &R, &C, &M);
		if(R == 1 || C == 1 || R*C-M == 1) {
			int remain = R*C-M;
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					if(i == 0 && j == 0) putchar('c');
					else if(remain > 0) putchar('.');
					else putchar('*');
					remain--;
				}
				putchar('\n');
			}
		} else if(solve()) {
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					if(i == 0 && j == 0) putchar('c');
					else putchar(mines[i][j]);
				}
				putchar('\n');
			}
		} else {
			puts("Impossible");
		}
	}
	return 0;
}

