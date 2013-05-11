#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int c, n;
string wildcard;
string filename;
int dp[101][101];

bool isMatching(int wi, int fi)
{
	if(wi >= wildcard.length())
	{
		return fi >= filename.length();
	}
	if(fi >= filename.length())
	{
		while(wi < wildcard.length()) if(wildcard[wi++] != '*') return false;
		return true;
	}

	int& ret = dp[wi][fi];

	if(ret != -1) return ret;

	ret = false;

	if(wildcard[wi] == '?' || wildcard[wi] == filename[fi])
	{
		ret = isMatching(wi+1, fi+1);
	}
	else if(wildcard[wi] == '*')
	{
		ret = isMatching(wi, fi+1);
		ret = ret || isMatching(wi+1, fi); 
		ret = ret || isMatching(wi+1, fi+1);
	}

	return ret;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		cin >> wildcard;
		scanf("%d", &n);

		vector<string> result;
		while(n --> 0)
		{
			cin >> filename;

			memset(dp, -1, sizeof(dp));

			if(isMatching(0, 0))
			{
				result.push_back(filename);
			}
		}

		sort(result.begin(), result.end());
		for(int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
	}
	return 0;
}
