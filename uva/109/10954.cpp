#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	for(;;)
	{
		int n;
		scanf("%d", &n);
		priority_queue<int> pq;
		if(n == 0) break;
		while(n --> 0)
		{
			int r;
			scanf("%d", &r);
			pq.push(-r);
		}
		int result = 0;
		while(pq.size() != 1)
		{
			int t1 = -pq.top(); pq.pop();
			int t2 = -pq.top(); pq.pop();
			pq.push(-(t1+t2));
			result += t1+t2;
		}
		printf("%d\n", result);
	}
	return 0;
}

