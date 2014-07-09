class Solution {
	public:
		vector<vector<int>> threeSum(vector<int> &number) {
			unordered_map<int, int> nextIndex;
			unordered_map<int, int> prevIndex;

			vector<vector<int>> result;

			sort(number.begin(), number.end());

			for(int i = 0; i < number.size(); i++) {
				nextIndex[number[i]] = i+1;
			}
			for(int i = number.size() - 1; i >= 0; i--) {
				prevIndex[number[i]] = i-1;
			}

			for(int i = 0; i < number.size(); i = nextIndex[number[i]]) {
				int left = i + 1;
				int right = number.size() - 1;

				while(left < right) {
					int sum = number[i] + number[left] + number[right];
					if(sum == 0) {
						vector<int> p = {number[i], number[left], number[right]};
						result.push_back(p);

						left = nextIndex[number[left]];
						right = prevIndex[number[right]];
					}else if(sum < 0) {
						left = nextIndex[number[left]];
					}else {
						right = prevIndex[number[right]];
					}
				}
			}
			return result;
		}
};


