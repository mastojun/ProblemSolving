#include <cstdio>
#include <set>

using namespace std;

set<int> num;
int order[50000];
int result[50000];

int main()
{
	int C, N;

	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d", &N);
		num.clear();

		for(int i = 0; i < N; i++)
		{
			scanf("%d", order+i);
			num.insert(i+1);
		}

		for(int i = N-1; i >= 0; i--)
		{
			int findNumber = i - order[i];
			auto itr = num.upper_bound(findNumber);
			result[i] = *itr;
			num.erase(itr);
		}

		for(int i = 0; i < N; i++)
		{
			printf("%d%c", result[i], i == N-1 ? '\n' : ' ');
		}

	}

	return 0;
}

