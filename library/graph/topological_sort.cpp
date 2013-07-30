vector<int> seen, order;

void dfs(int here){
	seen[here] = 1;
	for(int there = 0; there < adj.size(); ++there){
		if(adj[here][there] && !seen[there]){
			dfs(there);
		}
	}
	order.push_back(here);
}

vector<int> topologicalSort(){
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	for(int i = 0; i < n; ++i) if(!seen[i]) dfs(i);
	reverse(order.begin(), order.end());

	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			if(adj[order[j]][order[i]]){
				return vector<int>();
			}
		}
	}

	return order;
}

