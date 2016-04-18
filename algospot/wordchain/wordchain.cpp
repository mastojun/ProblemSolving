/**
 * 단어를 간선으로, 알파벳을 노드로 바꾸어서 해밀턴 경로를 오일러 경로로 바꾸어 푸는 문제
 * 으아.. 이런건 어떻게 떠올린데... ;-(
 */
#include <cstring>

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int C;
int n;

vector<string> word;

vector<string> words[26][26];
int in[26];
int out[26];
char startPoint;
vector<string> result;
set<string> used;
void generate() {
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));

  result.clear();
  used.clear();

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      words[i][j].clear();
    }
  }

  for (string& str : word) {
    int start = str[0] - 'a';
    int end = str[str.length() - 1] - 'a';
    words[start][end].push_back(str);
    out[start]++;
    in[end]++;
  }
}

bool isPossible() {
  char largeOut = -1;
  char largeIn = -1;
  for (int i = 0; i < 26; i++) {
    if (abs(in[i] - out[i]) > 1) {
      return false;
    } else if (in[i] > out[i]) {
      if (largeIn != -1) return false;
      largeIn = i;
    } else if (in[i] < out[i]) {
      if (largeOut != -1) return false;
      largeOut = i;
    }
  }

  if (largeIn != -1 && largeOut != -1) {
    startPoint = largeOut;
    return true;
  }

  if (largeIn != -1 || largeOut != -1) {
    return false;
  }

  for (int i = 0; i < 26; i++) {
    if (in[i]) {
      startPoint = i;
      break;
    }
  }

  return true;
}

void go(char position, string word) {

  for (int i = 0; i < 26; i++) {
    for (string str : words[position][i]) {
      if (used.find(str) != used.end()) {
        continue;
      }
      used.insert(str);
      go(i, str);
    }
  }

  if (word != "") {
    result.push_back(word);
  }
}

int main()
{
  cin >> C;

  while (C --> 0) {
    cin >> n;
    word.clear();

    for (int i = 0; i < n; i++) {
      string w;
      cin >> w;
      word.push_back(w);
    }

    generate();

    if (isPossible()) {
      go(startPoint, "");
      reverse(result.begin(), result.end());
      for (string str : result) {
        cout << str << " ";
      }
      cout << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }

  return 0;
}

