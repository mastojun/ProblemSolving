#include <cstdio>
#include <vector>

int C, H, W;
char board[21][21];
char shape[4][2][3] = {
	{
		{0, 1, 1},
		{0, 1, 0},
	},
	{
		{0, 1, 1},
		{0, 0, 1},
	},
	{
		{0, 1, 0},
		{0, 1, 1},
	},
	{
		{0, 1, 0},
		{1, 1, 0},
	}
};

bool inBoardArea(int h, int w)
{
	if(h < 0) return false;
	if(h >= H) return false;
	if(w < 0) return false;
	if(w >= W) return false;
	return true;
}

bool canPut(int h, int w, int idx)
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(shape[idx][i][j] == 1)
			{
				if(inBoardArea(h+i, w+j-1) == false) return false;
				if(board[h+i][w+j-1] != '.') return false;
			}
		}
	}

	return true;
}

void put(int h, int w, int idx)
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(shape[idx][i][j] == 1)
			{
				board[h+i][w+j-1] = '@';
			}
		}
	}
}

void off(int h, int w, int idx)
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(shape[idx][i][j] == 1)
			{
				board[h+i][w+j-1] = '.';
			}
		}
	}
}

int numberOfBoardCover(int h, int w)
{
	if(h == H){return 1;}
	if(w == W){return numberOfBoardCover(h+1, 0);}
	if(board[h][w] != '.'){return numberOfBoardCover(h, w+1);}

	int result = 0;
	for(int i = 0; i < 4; i++)
	{
		if(canPut(h, w, i))
		{
			put(h, w, i);
			result += numberOfBoardCover(h, w+1);
			off(h, w, i);
		}
	}

	return result;
}

int main()
{
	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d %d", &H, &W);
		for(int i = 0; i < H; i++)
		{
			scanf("%s", board[i]);
		}

		printf("%d\n", numberOfBoardCover(0, 0));
	}

	return 0;
}
