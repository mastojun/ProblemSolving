class Solution {
	public:
		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			vector<int> nums;
			for(int ai = 0, bi = 0; ai < m || bi < n;) {
				if(ai >= m || bi >= n) {
					while(ai >= m && bi < n) {
						nums.push_back(B[bi++]);
					}
					while(bi >= n && ai < m) {
						nums.push_back(A[ai++]);
					}
				} else if(A[ai] < B[bi]) {
					nums.push_back(A[ai]);
					ai++;
				} else {
					nums.push_back(B[bi]);
					bi++;
				}
			}
			if(nums.size()%2 == 1) return nums[nums.size()/2];
			return (nums[nums.size()/2] + nums[nums.size()/2 - 1]) / 2.;
		}
};
