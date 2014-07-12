class Solution {
	public:
		int maxArea(vector<int> &height) {
			vector<pair<int, int>> heightWithIdx;
			for(int i = 0; i < height.size(); i++) {
				heightWithIdx.push_back(make_pair(-height[i], i));
			}

			sort(heightWithIdx.begin(), heightWithIdx.end());

			int minIdx = height.size();
			int maxIdx = 0;
			int result = 0;
			for(int i = 0; i < heightWithIdx.size(); i++) {
				minIdx = min(minIdx, heightWithIdx[i].second);
				maxIdx = max(maxIdx, heightWithIdx[i].second);

				result = max(result, (maxIdx - minIdx) * min(height[minIdx], height[maxIdx]));
			}

			return result;
		}
};
