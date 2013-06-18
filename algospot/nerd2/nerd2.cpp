#include <cstdio>
#include <map>

using namespace std;

int C, N;
int p, q;

map<int, int> nerds;

bool canInsert(int p, int q)
{
	auto upper = nerds.upper_bound(p);
	if(upper == nerds.end()) return true;

	return upper->second <= q;
}

void removeNoNerds(int p, int q)
{
	auto itr_last = nerds.lower_bound(p);
	auto itr_first = itr_last;

	if(itr_first == nerds.begin()) return;

	for(--itr_first; itr_first != nerds.begin(); --itr_first)
	{
		if(itr_first->second >= q) break;
	}

	if(itr_first->second >= q) ++itr_first;

	nerds.erase(itr_first, itr_last);
}

int main()
{
	scanf("%d", &C);
	while(C --> 0)
	{
		scanf("%d", &N);

		nerds.clear();

		int result = 0;
		for(int i = 0; i < N; i++)
		{
			scanf("%d %d", &p, &q);

			if(canInsert(p, q))
			{
				removeNoNerds(p, q);
				nerds.insert(make_pair(p, q));
			}
			result += nerds.size();
		}
		printf("%d\n", result);
	}

	return 0;
}

