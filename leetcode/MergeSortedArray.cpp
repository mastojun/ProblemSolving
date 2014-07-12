class Solution {
	public:
		void merge(int A[], int m, int B[], int n) {
			for(int last = m + n - 1; last >= 0; last--) {
				if(m <= 0 && n > 0 || m > 0 && n > 0 && A[m - 1] < B[n - 1]) {
					A[m + n - 1] = B[n - 1];
					n--;
				} else if(m > 0 && n <= 0 || m > 0 && n > 0 && A[m - 1] >= B[n - 1]) {
					A[m + n - 1] = A[m - 1];
					m--;
				}
			}
		}
};
