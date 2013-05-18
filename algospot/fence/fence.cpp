#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>
using namespace std;

int C, N;

struct Fence
{
	Fence(int h, int p):h(h), p(p){}
	int h, p;
};

int getArea(stack<Fence>& fence, int p)
{
	int result = 0;
	Fence topFence = fence.top(); fence.pop();
	if(fence.empty() == true){
		result = max(result, topFence.h*p);
	}
	else{
		Fence secondFence = fence.top();
		result = max(result, topFence.h*(p-secondFence.p-1));
	}
	return result;
}

int main()
{
	scanf("%d", &C);
	while(C --> 0)
	{
		scanf("%d", &N);
		stack<Fence> fence;
		int result = 0;
		for(int i = 0; i < N; i++)
		{
			int h;
			scanf("%d", &h);
			while(fence.empty() == false)
			{
				Fence topFence = fence.top();
				if(topFence.h > h)
				{
					result = max(result, getArea(fence, i));
				}
				else
				{
					break;
				}
			}
			fence.push(Fence(h, i));
		}

		while(fence.empty() == false)
		{
			result = max(result, getArea(fence, N));
		}

		printf("%d\n", result);
	}

	return 0;
}
