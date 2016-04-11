#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ff(const string& str) {
  vector<int> result(str.length(), 0);

  int matched = 0;
  for (int i = 1; i < str.length(); i++) {
    while (matched != 0 && str[i] != str[matched]) {
      matched = result[matched - 1];
    }

    if (str[i] == str[matched]) {
      matched++;
      result[i] = matched;
    }
  }

  return result;
}

int main() {
  int C;
  cin >> C;

  while (C --> 0) {
    string str;
    cin >> str;
    string rev = str;
    reverse(rev.begin(), rev.end());

    vector<int> revFF = ff(rev);
    vector<int> result(str.length(), 0);

    int matched = 0;
    for (int i = 0; i < str.length(); i++) {
      while (matched != 0 && rev[matched] != str[i]) {
        matched = revFF[matched - 1];
      }

      if (str[i] == rev[matched]) {
        result[i] = ++matched;
      }
    }

    cout << str.length()*2 - result[str.length() - 1] << endl;

  }
  return 0;
}

