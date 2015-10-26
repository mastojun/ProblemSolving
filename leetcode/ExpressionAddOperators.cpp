/**
 * T!L!E!
 * 4^n 으로 모든 수식을 만든 다음에 stack으로 계산기 품
 * 입력 : "3456237490", 9191 에 대해서 TLE 받음
 */
class Solution {
public:
	Solution() {
		operators.push_back("+");
		operators.push_back("*");
		operators.push_back("-");
		operators.push_back("");
	}
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		solve(result, num, 0, target);
		return result;
	}
private:
	vector<string> operators;
	void solve(vector<string>& result, string num, int pos, int target) {
		if (pos >= num.size()) {
			if (isSame(num, target)) result.push_back(num);
			return;
		}

		int opIndex = 0;
		if (pos == 0 || pos + 1 > num.size()) opIndex = 3;
		for (; opIndex < 4; opIndex++) {
			solve(result, num.substr(0, pos) + operators[opIndex] + num.substr(pos), pos + (opIndex == 3 ? 1 : 2), target);
		}
	}

	bool isSame(string formula, int target) {
		stack<int> nums;
		stack<char> oper;

		int num = 0;
		int len = 0;
		for (int i = 0; i < formula.length(); i++) {
			switch (formula[i]) {
			case '-':
			case '+':
				nums.push(num);
				num = 0;
				len = 0;
				while (oper.size() > 0 && nums.size() > 1) {
					int right = nums.top(); nums.pop();
					int left = nums.top(); nums.pop();
					char op = oper.top(); oper.pop();
					nums.push(cal(left, op, right));
				}
				oper.push(formula[i]);
				break;
			case '*':
				nums.push(num);
				num = 0;
				len = 0;
				while (oper.size() > 0 && oper.top() == '*' && nums.size() > 1) {
					int right = nums.top(); nums.pop();
					int left = nums.top(); nums.pop();
					char op = oper.top(); oper.pop();
					nums.push(cal(left, op, right));
				}
				oper.push(formula[i]);
				break;
			default:
				num *= 10;
				num += formula[i] - '0';
				len++;
				if (len > 1 && num < 10) return false;
			}
		}
		nums.push(num);
		while (oper.size() > 0 && nums.size() > 1) {
			int right = nums.top(); nums.pop();
			int left = nums.top(); nums.pop();
			char op = oper.top(); oper.pop();
			nums.push(cal(left, op, right));
		}
		return nums.top() == target;
	}

	int cal(int left, char op, int right) {
		switch (op) {
		case '+': return left + right;
		case '-': return left - right;
		}
		return left * right;
	}
};

