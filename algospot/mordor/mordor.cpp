#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int C, N, Q;
int high[100000];

struct Result {
	Result(int _min = 200000, int _max = 0) : min(_min), max(_max) {}

	Result(Result& l, Result& r) {
		setValue(l, r);
	}

	int setValue(Result& l, Result& r) {
		min = ::min(l.min, r.min);
		max = ::max(l.max, r.max);
	}

	int setValue(int value) {
		min = max = value;
	}

	int difficulty() { return max - min; }

private:
	int min, max;
};

struct RMQ {

	void init(int* high, int size) {
		this->size = size;
		this->range.resize(4 * size);
		init(high, 0, size - 1, 1);
	}

	int query(int left, int right) {
		return query(left, right, 0, size-1, 1).difficulty();
	}

private:

	int size;
	vector<Result> range;
	Result INF_RESULT;

	Result* init(int* high, int left, int right, int node) {
		if(left == right) {
			range[node].setValue(high[left]);
		} else {
			int mid = (left + right) / 2;
			Result* leftResult = init(high, left, mid, node*2);
			Result* rightResult = init(high, mid + 1, right, node*2 + 1);
			range[node].setValue(*leftResult, *rightResult);
		}

		return &range[node];
	}

	Result query(int left, int right, int nodeLeft, int nodeRight, int node) {
		if(nodeRight < left || right < nodeLeft) return INF_RESULT;
		if(left <= nodeLeft && right >= nodeRight) return range[node];

		int mid = (nodeLeft + nodeRight) / 2;
		Result leftResult = query(left, right, nodeLeft, mid, node * 2);
		Result rightResult = query(left, right, mid + 1, nodeRight, node * 2 + 1);

		return Result(leftResult, rightResult);
	}
};

int main() {
	scanf("%d", &C);

	RMQ rmq;

	while(C --> 0) {
		scanf("%d %d", &N, &Q);
		for(int i = 0; i < N; i++) {
			scanf("%d", high + i);
		}

		rmq.init(high, N);


		for(int i = 0; i < Q; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			printf("%d\n", rmq.query(a, b));
		}
	}
	return 0;
}
