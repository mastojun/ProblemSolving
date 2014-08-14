ass Solution {
	public:
		int singleNumber(int A[], int n) {
			int bits[32] = {0};
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < 32; j++) {
					bits[j] += ((A[i] >> j) & 1) ? 1 : 0;
				}
			}
			int result = 0;

			for(int j = 0; j < 32; j++) {
				result |= (bits[j] %3 == 1) << j;
			}

			return result;
		}
};
