#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> words;
int wordCounter;

vector<string> one = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> ten = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string toString(int num) {
  string result;
  int h = num / 100;
  int t = num % 100 / 10;
  int o = num % 10;

  if (h) {
    result += one[h - 1] + "hundred";
  }
  if (t) {
    if (t == 1) {
      result += ten[t * 10 + o - 10];
    } else {
      result += tens[t - 2];
    }
  }
  if (o && t != 1) {
    result += one[o - 1];
  }

  return result;
}

string solve() {
  for (int i = 1; i < 1000; i++) {
    if (toString(i).length() + wordCounter == i) {
      return toString(i);
    }
  }
  return "$";
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    if (word != "$") {
      wordCounter += word.length();
    }
    words.push_back(word);
  }

  string number = solve();
  for (string w : words) {
    if (w == "$") cout << number;
    else cout << w;
    cout << ' ';
  }

  return 0;
}

