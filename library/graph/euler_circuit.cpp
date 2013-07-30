vector<vector<int>> adj;

void getEulerCircuit(int here, vector<int>& circuit){
	for(int there = 0; there < adj.size(); ++there){
		while(adj[here][there] > 0){
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}

