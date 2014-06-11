#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int nums[1000];
	for(;;)
	{
		scanf("%d", &n);
		if(n == 0) break;

		for(int i = 0; i < n; i++) scanf("%d", nums + i);

		sort(nums, nums + n);

		map<int, set<int> > sub;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				int subtraction = nums[i] - nums[j];

				sub[subtraction].insert(nums[j]);
			}
		}

		int result = -987654321;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				int sum = nums[i] + nums[j];
				set<int>& subkey = sub[sum];

				for(set<int>::reverse_iterator itr = subkey.rbegin(); itr != subkey.rend(); ++itr)
				{
					if(abs(*itr) != abs(nums[i]) && abs(*itr) != abs(nums[j]))
					{
						if(sum+*itr > result) result = sum+*itr;
						break;
					}
				}
			}
		}

		if(result == -987654321) puts("no solution");
		else					printf("%d\n", result);
	}

	return 0;
}

