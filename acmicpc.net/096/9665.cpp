/**
 * 범위가 작으므로
 * 모든 가능한걸 다 해보면 되는 문제
 */
#include <iostream>
#include <string>

using namespace std;

string origin;
string insert;
int score[4];

int toIdx(char c) {
  switch(c) {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
  }
  return -1;
}

int solve(int oi, int ii) {
  if (ii >= insert.length()) {
    return 0;
  }

  if (oi >= origin.length()) {
    int result = 0;
    for (int i = ii; i < insert.length(); i++) {
      result += score[toIdx(insert[i])];
    }
    return result;
  }

  if (origin[oi] == insert[ii]) return solve(oi + 1, ii + 1);

  return solve(oi, ii + 1) + score[toIdx(insert[ii])];
}

int solve() {
  int result = 50000000;
  for (int i = 0; i <= origin.size(); i++) {
    result = min(result, solve(i, 0));
  }

  return result;
}

int main() {

  cin >> origin;
  cin >> insert;

  for (int i = 0; i < 4; i++) {
    cin >> score[i];
  }

  cout << solve() << endl;

  return 0;
}

