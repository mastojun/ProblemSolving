#include <cstdio>
#include <algorithm>

using namespace std;

int heap[15000];
int num;
int poll()
{
	int top = heap[0];
	heap[0] = heap[--num];

	int idx = 0;
	for(;;){

		int swapIdx = idx;
		int tmpIdx = idx*2+1;
		if(tmpIdx < num && heap[tmpIdx] < heap[swapIdx]){
			swapIdx = tmpIdx;
		}
		tmpIdx++;
		if(tmpIdx < num && heap[tmpIdx] < heap[swapIdx]){
			swapIdx = tmpIdx;
		}
		if(idx == swapIdx) break;
		swap(heap[idx], heap[swapIdx]);

		idx = swapIdx;
	}
	return top;
}

void push(int n)
{
	heap[num++] = n;

	int idx = num-1;
	int p = (idx-1)>>1;
	while(idx && heap[idx] < heap[p]){
		swap(heap[idx], heap[p]);
		idx = p;
		p = (idx-1)>>1;
	}
}
inline int nextInt() {
    #define getchar getchar_unlocked
	register int s = 0, ch;
	for(ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for(s = ch - '0', ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		s = s * 10 + ch - '0';
	return s;
}

int main()
{
	while(num = nextInt())
	{
		for(int i = 0; i < num; i++)
		{
			heap[i] = nextInt();
		}
		sort(heap, heap + num);

		int result = 0;
		while(num > 1){
			int sum = poll() + poll();
			result += sum;

			push(sum);
		}
		printf("%d\n", result);
	}

	return 0;
}

