#include <cstdio>
#include <vector>

using namespace std;

int C, V, W;
vector<vector<pair<int, int> > > adj_fast;
vector<vector<pair<int, int> > > adj_slow;
vector<int> result;

bool reachable[100][100];

bool solve(vector<vector<pair<int, int> > >& adj)
{
	result = vector<int>(V, 987654321);

	result[0] = 0;

	for(int i = 0; i < V-1; i++)
	{
		for(int here = 0; here < V; here++)
		{
			for(int j = 0; j < adj[here].size(); j++)
			{
				int there = adj[here][j].first;
				int cost = adj[here][j].second;

				if(result[there] > result[here] + cost)
				{
					result[there] = result[here] + cost;
				}
			}
		}
	}

	for(int here = 0; here < V; here++)
	{
		for(int j = 0; j < adj[here].size(); j++)
		{
			int there = adj[here][j].first;
			int cost = adj[here][j].second;

			if(result[there] > result[here] + cost)
			{
				if(reachable[0][here] && reachable[here][1]){
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d %d", &V, &W);

		adj_fast = vector<vector<pair<int, int> > >(V);
		adj_slow = vector<vector<pair<int, int> > >(V);


		for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) reachable[i][j] = i == j;

		for(int i = 0; i < W; i++)
		{
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			adj_fast[a].push_back(make_pair(b, d));
			adj_slow[a].push_back(make_pair(b, -d));
			reachable[a][b] = true;
		}

		for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) for(int k = 0; k < V; k++) reachable[j][k] = reachable[j][k] || (reachable[j][i] && reachable[i][k]);

		bool infinity = solve(adj_fast);

		if(result[1] < 500000000){
			if(infinity) printf("INFINITY ");
			else printf("%d ", result[1]);

			if(solve(adj_slow)) puts("INFINITY");
			else printf("%d\n", -result[1]);
		}else{
			puts("UNREACHABLE");
		}
	}

	return 0;
}

