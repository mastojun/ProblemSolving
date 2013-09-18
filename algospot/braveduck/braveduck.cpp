#include <cstdio>
#include <vector>

using namespace std;

int c;
int j;
int n;

struct Point
{
	int x, y;
	bool connected[102];

	bool within(Point& p, int length)
	{
		return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y) <= length*length;
	}
} point[102];

bool visited[102];

bool connected(int s, int e)
{
	if(point[s].connected[e]) return true;
	if(visited[s]) return false;
	visited[s] = true;
	bool result = false;
	for(int i = 0; i < n+2 && result == false; i++)
	{
		if(point[s].connected[i]){
			result = connected(i, e);
		}
	}

	return result;
}

int main()
{
	scanf("%d", &c);

	while(c --> 0)
	{
		scanf("%d", &j);
		scanf("%d %d", &point[0].x,&point[0].y);
		scanf("%d %d", &point[1].x, &point[1].y);

		scanf("%d" ,&n);

		for(int i = 2; i < n+2; i++)
		{
			scanf("%d %d", &point[i].x, &point[i].y);
		}

		for(int i = 0; i < n+2; i++)
		{
			visited[i] = false;
			for(int k = 0; k < n+2; k++)
			{
				point[i].connected[k] = (i != k && point[i].within(point[k],j));
			}
		}

		puts(connected(0, 1) ? "YES" : "NO");
	}

	return 0;
}


