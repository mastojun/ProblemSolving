/**
 * KMP의 failure function 을 이용한 문제
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> generateFailureFunction(string& str) {
  vector<int> result(str.length());

  int length = 0;
  for (int i = 1; i < str.length(); i++) {
    while (length != 0 && str[length] != str[i]) {
      length = result[length - 1];
    }

    if (str[length] == str[i]) {
      result[i] = ++length;
    } else {
      result[i] = 0;
    }
  }

  return result;
}

int main() {

  string papa;
  cin >> papa;
  string mama;
  cin >> mama;

  string parents = papa + mama;

  vector<int> ff = generateFailureFunction(parents);

  vector<int> result;

  int length = parents.length();
  while (length > 0) {
    result.push_back(length);
    length = ff[length - 1];
  }

  reverse(result.begin(), result.end());

  for (int n : result) {
    printf("%d ", n);
  }

  return 0;
}

