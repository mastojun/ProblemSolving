class Solution {
public:
	vector<int> checker[3];
	int n;
	// 문제에 n의 범위가 없지만 dfs로 시도해봄
    int totalNQueens(int n) {

		for(int i = 0; i < 3; i++) {
			checker[i].resize(n*2, false);
		}

		this->n = n;
		return solve(0);
	}
private:
	int solve(int line) {
		if(line == n) return 1;

		int result = 0;

		for(int i = 0; i < n; i++) {
			if(checker[0][i] == false
					&& checker[1][n + i - line] == false
					&& checker[2][i + line] == false) {
				checker[0][i] = checker[1][n + i - line] = checker[2][i + line] = true;

				result += solve(line + 1);

				checker[0][i] = checker[1][n + i - line] = checker[2][i + line] = false;
			}
		}

		return result;
	}
};
