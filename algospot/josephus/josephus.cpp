#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

int C, N, K;

int main()
{
	scanf("%d", &C);
	while(C --> 0)
	{
		scanf("%d %d", &N, &K);
		list<int> soldier;
		for(int i = 1; i < N; i++) soldier.push_back(i+1);
		auto soldier_itr = soldier.begin();
		for(int i = 3; i < N; i++){
			for(int j = 1; j < K; j++){
				soldier_itr++;
				if(soldier_itr == soldier.end()) soldier_itr = soldier.begin();
			}
			soldier_itr = soldier.erase(soldier_itr);
			if(soldier_itr == soldier.end()) soldier_itr = soldier.begin();

		}
		printf("%d %d\n", min(soldier.front(), soldier.back()),
							max(soldier.front(), soldier.back()));
	}
	return 0;
}

