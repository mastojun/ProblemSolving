#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <list>
using namespace std;

int C, V, E, N;
long long pathCountFromStartToEnd[101];
long long pathCountFromEndToStart[101];

vector<int> shortestPath;
vector<int> shortestPathReverse;

vector<int> dijkstra(vector<vector<pair<int, int> > > place, int src, long long* pathCount)
{
	vector<int> distance = vector<int>(V+1, 987654321);
	distance[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	pathCount[src] = 1;

	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(distance[here] < cost) continue;
		for(int i = 0; i < place[here].size(); i++)
		{
			int there = place[here][i].first;
			int nextDist = cost + place[here][i].second;
			if(distance[there] > nextDist){
				distance[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
				pathCount[there] = pathCount[here];
			}else if(distance[there] == nextDist){
				pathCount[there] += pathCount[here];
			}
		}
	}

	return distance;
}

long long getGCD(long long a, long long b)
{
	if(b == 0) return a;
	return getGCD(b, a%b);
}

int main()
{       
	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d %d %d", &V, &E, &N);
		vector<vector<pair<int, int> > > place(V+1);

		for(int i = 0; i < E; i++)
		{
			int A, B, M;
			scanf("%d %d %d", &A, &B, &M);
			place[A].push_back(make_pair(B, M));
			place[B].push_back(make_pair(A, M));
		}

		fill(pathCountFromStartToEnd, pathCountFromStartToEnd + V + 1, 0);
		fill(pathCountFromEndToStart, pathCountFromEndToStart + V + 1, 0);

		pathCountFromStartToEnd[V] = 1;
		pathCountFromEndToStart[1] = 1;


		shortestPath = dijkstra(place, 1, pathCountFromEndToStart);
		shortestPathReverse = dijkstra(place, V, pathCountFromStartToEnd);

		for(int i = 0; i < N; i++)
		{
			int P;
			scanf("%d", &P);
			long long total = pathCountFromStartToEnd[1];
			long long position = 0;
			if(shortestPath[P] + shortestPathReverse[P] == shortestPathReverse[1])
			{
				position = pathCountFromStartToEnd[P] * pathCountFromEndToStart[P];
			}

			long long gcd = getGCD(total, position);

			if(gcd == 0) gcd = 1;

			printf("%lld/%lld\n", position/gcd, total/gcd);
		}
	}

	return 0;
}

