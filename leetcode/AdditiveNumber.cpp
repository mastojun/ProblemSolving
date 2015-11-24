/**
 * integer범위의 숫자만 다룬다고 가정을 하고
 * leading zero 체크, 각 합이 다음 문자열의 시작과 같은지를 확인
 * dfs (?)
 */
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if (i + j >= num.length()) break;
                if (isAdditiveNumber(num, 0, i, i, i + j)) return true;
            }
        }

        return false;
    }

private:
    bool isAdditiveNumber(string& num, int ls, int le, int rs, int re) {
        if (re > num.length()) return false;
        if (re - rs > 1 && num[rs] == '0') return false;
        if (le - ls > 1 && num[ls] == '0') return false;
        if (re == num.length()) return true;

        long long left = to_integer(num, ls, le);
        long long right = to_integer(num, rs, re);
        string sum = to_string(left + right);
        if(!startWith(num, re, sum)) return false;
        return isAdditiveNumber(num, rs, re, re, re + sum.length());
    }

    long long to_integer(string& num, int s, int e) {
        long long result = 0;
        for (int i = s; i < e; i++) {
            result *= 10;
            result += num[i] - '0';
        }
        return result;
    }

    bool startWith(string& num, int s, string& cmp) {
        if (s + cmp.length() > num.length()) return false;
        for (int i = 0; i < cmp.length(); i++) {
            if(num[s + i] != cmp[i]) return false;
        }
        return true;
    }
};

