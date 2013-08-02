#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
string str;
string result;

int cache[2001][2001];

int commonPrefix(int a, int b)
{
	if(a >= str.length() || b >= str.length()) return 0;

	int& ret = cache[a][b];
	if(ret != -1) return ret;

	ret = 0;

	int len = 0;
	for(; a+len < str.length() && b+len < str.length(); ++len)
	{
		if(str[a+len] != str[b+len]) break;
	}

	for(int i = 0; i < len; i++)
	{
		cache[a+i][b+i] = len - i;
	}

	return ret;

}

string makeResult(int as, int bs, int len)
{
	string s[2];

	s[0] = str.substr(as, len*2+1);
	s[1] = str.substr(bs, len*2+1);

	sort(s, s+2);

	return s[0] + " " + s[1];
}

void updateResult(int as, int bs, int len)
{
	string candidate = makeResult(as, bs, len);
	if(result > candidate)
		result = candidate;
}


int main()
{
	cin >> T;

	while(T --> 0)
	{
		cin >> str;

		int longest = 0;

		memset(cache, -1, sizeof(cache));

		result = "lonely island";
		for(int i = 0; i < str.length(); ++i)
		{
			for(int j = i+1; j < str.length(); ++j)
			{
				int cp = commonPrefix(i, j);
				int cs = commonPrefix(i+cp+1, j+cp+1);

				if(cp <= cs && cp > 0)
				{
					if(cp > longest)
					{
						result = makeResult(i, j, cp);
						longest = cp;
					}
					if(cp == longest)
					{
						updateResult(i, j, cp);
					}
				}

			}
		}

		cout << result << endl;
	}

	return 0;
}

