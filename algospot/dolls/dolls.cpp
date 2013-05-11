#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <climits>

using namespace std;

int C;
int n, m;
vector<int> doll;
vector<int> ordered_doll;

int main()
{    
	scanf("%d", &C);

	while(C --> 0)
	{       
		scanf("%d %d", &n, &m);
		doll.resize(n);
		for(int i = 0; i < n; i++)
		{
			int d;
			scanf("%d", &d);
			doll[i] = d;
		}

		ordered_doll = doll;
		sort(ordered_doll.begin(), ordered_doll.end());

		int over = INT_MAX;

		for(int i = 0; i < n; i++)
		{
			if(ordered_doll[i] * (n-i) > m)
			{
				over = m/(n-i);
				m -= over*(n-i);
				break;
			}
			else
			{
				m -= ordered_doll[i];
			}
		}

		for(int i = 0; i < n; i++)
		{
			int pickCount;
			if(doll[i] <= over)
			{
				pickCount = doll[i];
			}
			else
			{
				pickCount = over;
				if(m != 0)
				{
					pickCount++;
					m--;
				}
			}
			printf("%d%c", pickCount, i == n-1? '\n' : ' ');
		}
	}

	return 0;
}

