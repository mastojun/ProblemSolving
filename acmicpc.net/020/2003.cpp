#include <iostream>

using namespace std;

int N, M;
int A[10000];

int main() {
	cin >> N >> M;
	for (int i = 0 ;i < N; i++) {
		cin >> A[i];
	}

	int sum = 0;
	int result = 0;
	for (int i = 0, j = 0; i < N; i++) {
		sum += A[i];
		while(sum > M) {
			sum -= A[j++];
		}
		if(sum == M) result++;
		
	}

	cout << result << endl;

	return 0;
}

