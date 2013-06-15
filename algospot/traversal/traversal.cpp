#include <cstdio>
#include <vector>

using namespace std;

int C, N;

int pre[100];
int in[100];

vector<int> post;

void makePostOrder(int root, int left, int right)
{
	if(left > right) return;

	int inRootIdx;
	for(inRootIdx  = left; inRootIdx <= right; inRootIdx++) if(pre[root] == in[inRootIdx]) break;

	makePostOrder(root + 1, left, inRootIdx - 1);
	makePostOrder(root + (inRootIdx - left) + 1, inRootIdx + 1, right);
	post.push_back(pre[root]);
}

int main()
{
	scanf("%d", &C);
	while(C --> 0)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", pre+i);
		for(int i = 0; i < N; i++) scanf("%d", in+i);
		post.clear();
		makePostOrder(0, 0, N-1);
		for(int i = 0; i < N; i++) printf("%d%c", post[i], i == N-1 ? '\n' : ' ');
	}

	return 0;
}

