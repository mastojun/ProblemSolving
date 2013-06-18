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
	for(auto itr = nerds.lower_bound(p); itr != nerds.begin(); --itr){
		if(itr == nerds.end()) continue;
		if(itr->first >= p) continue;
		if(itr->second < q){
			nerds.erase(itr);
		}
		else break;
	}
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

