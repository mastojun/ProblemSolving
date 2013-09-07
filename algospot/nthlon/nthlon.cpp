#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int C, M;

// 0 : 가상의 시작 노드
// 1 : -200
// 201 : 0
// 401 : +200
int matrix[402][402];

int dijkstra(int idx)
{
	vector<int> result(402, 987654321);

	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, 0));

	while(q.empty() == false)
	{
		int dist = -q.top().first;
		int here = q.top().second;
		q.pop();

		if(result[here] < dist) continue;

		for(int there = 1; there < 402; there++)
		{
			int nextDist = dist+matrix[here][there];

			if(nextDist < result[there])
			{
				q.push(make_pair(-nextDist, there));
				result[there] = nextDist;
			}
		}
	}

	return result[idx];
}

int main()
{
	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d", &M);

		for(int i = 0; i < 402; i++)
		{
			for(int j = 0; j < 402; j++)
			{
				matrix[i][j] = 987654321;
			}
		}

		for(int i = 0; i < M; i++)
		{
			int s, e;
			scanf("%d %d", &s, &e);

			for(int i = 0; i < 402; i++)
			{
				int next = (i?i:201) + (s-e);
				if(next < 1 || 401 < next) continue;
				matrix[i][next] = min(matrix[i][next], s);
			}
		}
		int result = dijkstra(201);
		if(result == 987654321) puts("IMPOSSIBLE");
		else printf("%d\n", dijkstra(201));
	}

	return 0;
}


