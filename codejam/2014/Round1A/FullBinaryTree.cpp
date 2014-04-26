#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> graph[1001];
bool visited[1001];
int childCount[1001];
int dp[1001];

int childCountFunc(int root) {
	int& ret = childCount[root];
	if(ret != -1) return ret;
	ret = 0;
	visited[root] = true;
	for(auto i : graph[root]) {
		if(visited[i] == false) {
			ret += childCountFunc(i) + 1;
		}
	}

	visited[root] = false;
	return ret;
}

int minimumValue(int root) {

	int& ret = dp[root];

	if(ret != -1) return ret;

	int totalSum = 0;
	int child = 0;
	visited[root] = true;
	for(auto i : graph[root]) {
		if(visited[i] == false) {
			totalSum += childCountFunc(i);
			child++;
		}
	}


	ret = childCountFunc(root);
	if(child >= 2)
		for(auto i : graph[root]) {
			for(auto j : graph[root]) {
				if(i == j) continue;
				if(visited[i]) continue;
				if(visited[j]) continue;
				ret = min(ret, childCountFunc(root) - childCountFunc(i) - childCountFunc(j) - 2 + minimumValue(i) + minimumValue(j));
			}
		}

	visited[root] = false;
	return ret;
}

int main() {

	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {
		scanf("%d", &N);

		for(int i = 1; i <= N; i++) {
			graph[i].clear();
		}

		for(int i = 1; i < N; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		int result = N*2;
		int root = 0;
		for(int i = 1; i <= N; i++) {
			for(int i = 1; i <= N; i++) {
				childCount[i] = -1;
				dp[i] = -1;
			}
			childCountFunc(i);
			for(int i = 1; i <= N; i++) if(childCount[i] == -1) childCount[i] = 0;
			if(result > minimumValue(i)) {
				result = minimumValue(i);
				root = i;
			}
		}

		printf("Case #%d: %d\n", c, result);
	}
	return 0;
}

