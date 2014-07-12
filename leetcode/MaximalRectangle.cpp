class Solution {
	public:
		int maximalRectangle(vector<vector<char> > &matrix) {
			if(matrix.size() == 0) return 0;
			vector<vector<int>> sum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
			for(int i = 0; i < matrix.size(); i++) {
				for(int j = 0; j < matrix[i].size(); j++) {
					if(j == 0) sum[i][j] = matrix[i][j] == '1';
					else sum[i][j] = (matrix[i][j] == '1') + sum[i][j-1];
				}
			}

			int result = 0;
			for(int i = 0; i < matrix[0].size(); i++) {
				for(int j = i; j < matrix[0].size(); j++) {
					int s = 0;
					for(int l = 0; l < matrix.size(); l++) {
						if(sum[l][j] - sum[l][i] + (matrix[l][i] == '1') == j - i + 1) {
							s += j - i + 1;
							result = max(result, s);
						} else {
							s = 0;
						}
					}
				}
			}

			return result;
		}
};
