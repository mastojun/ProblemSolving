class Solution {
	public:
		int sqrt(int x) {
			int left = 0;
			int right = 46340;
			while(left < right) {
				int mid = (left+right)/2;

				if(mid * mid < x) {
					left = mid + 1;
				} else {
					right = mid;
				}
			}

			return left*left <= x ? left : left - 1;
		}
};
