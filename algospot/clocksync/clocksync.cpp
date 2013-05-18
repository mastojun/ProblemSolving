#include <cstdio>
#include <cstring>
#include <vector>

int C;
int clock[16];
int clickGroup[10][6] =
{
	{11, -1},
	{ 8, 12, -1},
	{10, -1},
	{ 9, 13, -1},
	{ 6, -1},
	{ 7, -1},
	{ 4,  5, -1},
	{ 3, -1},
	{14, 15, -1},
	{ 0, 1, 2, -1},
};

int clickClock[10][6] =
{
	{ 3, 7, 9,11,-1},
	{ 6, 7, 8,10,12,-1},
	{ 4,10,14,15,-1},
	{ 3, 4, 5, 9, 13,-1},
	{ 0, 4, 5, 6, 7,-1},
	{ 4, 5, 7,14,15,-1},
	{ 1, 2, 3, 4, 5,-1},
	{ 3,14,15,-1},
	{ 0, 2,14,15,-1},
	{ 0, 1, 2,-1},
};

bool allSame(int idx)
{
	for(int i = 1; clickGroup[idx][i] != -1; ++i)
	{
		if(clock[clickGroup[idx][0]] != clock[clickGroup[idx][i]]) return false;
	}

	return true;
}

int numberOfClick(int idx)
{
	int result = (12-clock[clickGroup[idx][0]])/3;

	for(int i = 0; clickClock[idx][i] != -1; i++)
	{
		clock[clickClock[idx][i]] = clock[clickClock[idx][i]]+3*result;
		if(clock[clickClock[idx][i]] > 12) clock[clickClock[idx][i]] -= 12;
	}

	return result;
}

int numberOfTotalClick(int idx)
{
	if(idx == 10){return 0;}
	if(allSame(idx) == false){return -1;}

	int result = numberOfClick(idx);
	int remainResult = numberOfTotalClick(idx+1);

	if(remainResult == -1) return -1;
	return result + remainResult;
}

int main()
{
	scanf("%d", &C);

	while(C --> 0)
	{
		for(int i = 0; i < 16; i++)
		{
			scanf("%d", clock+i);
		}

		printf("%d\n", numberOfTotalClick(0));

	}

	return 0;
}
