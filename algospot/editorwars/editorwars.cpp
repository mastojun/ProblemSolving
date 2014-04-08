#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct OptimizedDisjointSet {
	vector<int> parent, rank;
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1){
		for(int i = 0; i < n; ++i){
			parent[i] = i;
		}
	}

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v){
		u = find(u); v = find(v);
		if(u == v) return;
		if(rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if(rank[u] == rank[v]) ++rank[v];
	}
};

int C, N, M;

int main()
{
	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d %d", &N, &M);

		OptimizedDisintSet(N);

		char operation[10];
		int a, b;
		int contradiction = 0;
		for(int i = 1; i <= M; i++)
		{
			scanf("%s %d %d", operation, &a, &b);
			if(contradiction) continue;

			if(operation[0] == 'A'){
				merge(a, b);
			}
			else{
				if(find(a) == find(b)){
					contradiction = i;
				}
			}
		}


	return 0;
}

