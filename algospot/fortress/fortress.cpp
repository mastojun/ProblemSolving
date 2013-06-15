#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int C, N;

struct Node
{
	int x, y, r;
	vector<Node*> nodes;

	Node(int x, int y, int r)
	{
		this->x = x; this->y = y; this->r = r;
	}

	void insert(Node* node)
	{
		for(auto n = nodes.begin(); n != nodes.end(); n++)
		{
			if((*n)->in(node))
			{
				(*n)->insert(node);
				return;
			}
		}

		nodes.push_back(node);
	}

	bool in(Node* node)
	{
		return sqrt(pow(node->x - x, 2) + pow(node->y - y, 2)) + node->r < r;
	}

	int height()
	{
		int height = 0;
		for(auto n = nodes.begin(); n != nodes.end(); n++)
		{
			height = max(height, 1 + (*n)->height());
		}
		return height;
	}

	int result()
	{
		vector<int> heights;
		for(auto n = nodes.begin(); n != nodes.end(); n++)
		{
			heights.push_back((*n)->height() + 1);
		}
		sort(heights.begin(), heights.end(), greater<int>());
		if(heights.size() == 0) return 0;
		if(heights.size() == 1) return heights[0];
		return heights[0] + heights[1];
	}
};

int x, y, r;

Node* head; //ignore memory leak

int main()
{
	scanf("%d", &C);

	while(C --> 0)
	{
		scanf("%d", &N);
		head = NULL;
		for(int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &x, &y, &r);

			if(head == NULL)
			{
				head = new Node(x, y, r);
			}
			else
			{
				head->insert(new Node(x, y, r));
			}
		}

		printf("%d\n", head->result());

	}

	return 0;
}

