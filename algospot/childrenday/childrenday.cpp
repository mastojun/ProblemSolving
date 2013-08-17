#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int T;
string C;
int N, M;

struct Node{
	Node() {
		for(int i = 0; i < 2; i++){
			parent[i] = -1;
			number[i] = -1;
			from[i] = -1;
		}
	}

	int parent[2];
	int number[2];
	int from[2];
};

string makeResult(vector<Node>& nodes, int now, int idx)
{
	string result;

	do
	{
		result.push_back(nodes[now].number[idx] + '0');
		int oIdx = idx;
		idx = nodes[now].from[oIdx];
		now = nodes[now].parent[oIdx];
	}while(now != -1);

	reverse(result.begin(), result.end());

	return result;
}

string solve()
{
	vector<Node> nodes(N);
	queue<int> q;
	queue<int> nums;

	q.push(0);
	nums.push(0);

	bool isFirst = true;
	while(!q.empty())
	{
		int re = q.front(); q.pop();
		int num = nums.front(); nums.pop();

		for(int i = 0; i < C.length(); ++i)
		{
			int now = (re * 10 + C[i] - '0')%N;
			int nowNum = num*10 + C[i] - '0';

			int from = num < N+M ? 0 : 1;
			int idx = nowNum < N+M ? 0 : 1;

			if(nodes[now].number[idx] != -1) continue;

			nodes[now].number[idx] = C[i] - '0';
			nodes[now].parent[idx] = isFirst ? -1 : re;
			nodes[now].from[idx] = from;

			if(now == M && nowNum >= (N+M)){
				return makeResult(nodes, now, idx);
			}else{
				q.push(now);
				if(nowNum > N+M) nowNum = N+M+1;
				nums.push(nowNum);
			}
		}
		isFirst = false;
	}

	return "IMPOSSIBLE";
}

int main()
{
	cin >> T;

	while(T --> 0)
	{
		cin >> C;
		cin >> N >> M;

		sort(C.begin(), C.end());

		cout << solve() << endl;
	}


	return 0;
}
