class Solution {
	public:
		int maxProfit(vector<int> &prices) {

			int result = 0;
			int prev = -1;

			for(auto price : prices) {
				if(prev == -1) {
					prev = price;
				} else if(prev < price) {
					result += price - prev;
				}
				prev = price;
			}

			return result;
		}
};

