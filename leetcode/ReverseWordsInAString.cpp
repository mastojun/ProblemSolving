#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


class Solution {
	public:
		void reverseWords(string &s) {
			string result;
			for(int e = s.length(), i = s.length() - 1; i >= 0; --i) {
				if(i == 0 || s[i] == ' ') {
					string word;
					for(int j = i; j < e; j++) {
						if(s[j] != ' ') word += s[j];
					}
					if(word.length() > 0){
						if(result.length() > 0) result += " ";
						result += word;
					}
					e = i;
				}
			}

			s = result;
		}
};

void simpleTest(string value, string expected) {
	static int counter = 0;
	Solution solve;
	solve.reverseWords(value);

	if(value != expected) {
		cout << counter << endl;
		cout << "Expected: " << expected << '|' << endl;
		cout << "Value   : " << value << '|' << endl;
		cout << "          ";
		for(int i = 0; i < value.length(); i++) {
			if(expected.length() <= i || value[i] != expected[i]) cout << '^';
			else cout << ' ';
		}
		cout << endl;
		exit(1);
	}
	counter++;
}

int main() {

	simpleTest("the sky is blue", "blue is sky the");
	simpleTest("  the sky   is blue","blue is sky the");
	simpleTest("the  sky   is blue   ","blue is sky the");
	return 0;
}
