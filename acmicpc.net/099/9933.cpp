#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

set<string> words;

int main() {
  int n;
  cin >> n;
  while(n --> 0) {
    string word;
    cin >> word;
    string rword = word;

    reverse(rword.begin(), rword.end());

    if (words.find(word) != words.end() || rword == word) {
      cout << word.length() << ' ' << word[word.length()/2] << endl;
      break;
    } else {
      words.insert(rword);
    }
  }

  return 0;
}

