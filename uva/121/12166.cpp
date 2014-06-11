#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

int t;
char input[1000000];

int main()
{
	scanf("%d\n",&t);
	while(t --> 0)
	{
		gets(input);

		int p = 0;

		map<long long, int> counter;

		int maxValue = 0;
		int numberOfNumber = 0;

		for(size_t i = 0; input[i]; i++)
		{
			if(input[i] == '[') p++;
			else if(input[i] == ']') p--;
			else if(isdigit(input[i])){
				long long n = input[i] - '0';
				while(isdigit(input[++i])){
					n = n * 10 + input[i] - '0';
				}
				i--;
				numberOfNumber++;
				maxValue = max(maxValue, ++counter[n << p]);
			}
		}

		printf("%d\n", numberOfNumber - maxValue);
	}

	return 0;
}

