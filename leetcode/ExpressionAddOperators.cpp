/**
 * stl stack을 사용하지 않고 간단한 배열로 처리함
 * 내 pc기준으로 기존 소스보다 두배정도 빨라짐 (orz..)
 */
class Solution {
public:
	Solution() {
		operators.push_back('+');
		operators.push_back('*');
		operators.push_back('-');
		operators.push_back(' ');
	}
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		if(num.length() == 0) return result;

		string blank_num(2 * num.length() - 1, ' ');
		for (int i = 0; i < num.length(); i++) {
			blank_num[i * 2] = num[i];
		}
		solve(result, blank_num, 1, target);
		return result;
	}
private:
	vector<char> operators;
	void solve(vector<string>& result, string& num, int pos, int target) {
		if (pos >= num.size()) {
			if (isSame(num, target)) {
				string r;
				for (auto c : num) {
					if (c == ' ') continue;
					r += c;
				}
				result.push_back(r);
			}
			return;
		}

		int opIndex = 0;
		for (; opIndex < 4; opIndex++) {
			num[pos] = operators[opIndex];
			solve(result, num, pos + 2, target);
		}
	}

	bool isSame(string formula, int target) {

		int num[3];
		int numIdx = 0;
		int op[2];
		int opIdx = 0;

		int n;
		int len = 0;
		for (int i = 0; i < formula.length(); i++) {
			switch (formula[i]) {
			case '-':
			case '+':
				num[numIdx++] = n;
				n = 0;
				len = 0;
				while (opIdx > 0) {
					int right = num[--numIdx];
					int left = num[--numIdx];
					num[numIdx++] = cal(left, op[--opIdx], right);
				}
				op[opIdx++] = formula[i];
				break;
			case '*':
				num[numIdx++] = n;
				n = 0;
				len = 0;
				while (opIdx > 0 && op[opIdx - 1] == '*') {
					int right = num[--numIdx];
					int left = num[--numIdx];
					num[numIdx++] = cal(left, op[--opIdx], right);
				}
				op[opIdx++] = formula[i];
				break;
			case ' ':
				break;
			default:
				n *= 10;
				n += formula[i] - '0';
				len++;
				if (len > 1 && n < 10) return false;
			}
		}
		num[numIdx++] = n;
		while (opIdx > 0) {
			int right = num[--numIdx];
			int left = num[--numIdx];
			num[numIdx++] = cal(left, op[--opIdx], right);
		}
		return num[0] == target;
	}

	int cal(int left, char op, int right) {
		switch (op) {
		case '+': return left + right;
		case '-': return left - right;
		}
		return left * right;
	}
};
