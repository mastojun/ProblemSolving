class Solution {
	public:
		int reverse(int x) {
			bool isNegative = false;
			int result = 0;
			if(x < 0) {
				isNegative = true;
				x = -x;
			}

			while(x) {
				result *= 10;
				result += x%10;
				x /= 10;
			}
			return isNegative ? -result : result;
		}
};
