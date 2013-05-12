#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int c, n;
int number;

map<int, int> resultSet;

int reverseNumber(int number, int from, int end)
{
	int fromIdx = 1;
	for(int i = 0; i < from; i++) fromIdx *= 10;
	int endIdx = 1;
	for(int i = 0; i < end; i++) endIdx *= 10;
	int subNumber = number%endIdx/fromIdx;
	int reverseNumber = 0;
	while(subNumber)
	{
		reverseNumber *= 10;
		reverseNumber += subNumber % 10;
		subNumber /= 10;
	}

	return (number/endIdx)*endIdx + reverseNumber*fromIdx + number%fromIdx;
}

int makeNumber(int to)
{
	int result = 0;
	for(int i = 1; i <= to; i++)
	{
		result *= 10;
		result += i;
	}
	return result;
}

int pre()
{
	for(int to = 1; to <= 8; to++)
	{
		int arr = makeNumber(to);

		queue<pair<int, int> > q;
		q.push(make_pair(arr, 0));
		resultSet.insert(make_pair(arr, 0));

		while(q.empty() == false)
		{
			int now = q.front().first;
			int step = q.front().second;
			q.pop();

			for(int i = 0; i < to; i++)
			{
				for(int j = i+1; j <= to; j++)
				{
					int nextNumber = reverseNumber(now, i, j);
					if(resultSet.find(nextNumber) == resultSet.end())
					{
						q.push(make_pair(nextNumber, step+1));
						resultSet.insert(make_pair(nextNumber, step+1));
					}
				}
			}
		}
	}
}

int arrayToNumber(int* item)
{
	int result = 0;
	for(int i = 0; i < n; i++)
	{
		result *= 10;
		result += item[i];
	}
	return result;
}

void input()
{
	int item[8];
	int sortedItem[8];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", item+i);
		sortedItem[i] = item[i];
	}

	sort(sortedItem, sortedItem+n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(item[j] == sortedItem[i])
			{
				item[j] = i+1;
			}
		}
	}
	number = arrayToNumber(item);
}

int solve()
{
	return resultSet[number];
}

int main()
{
	pre();
	scanf("%d", &c);
	while(c --> 0)
	{
		input();
		printf("%d\n", solve());
	}

	return 0;
}


