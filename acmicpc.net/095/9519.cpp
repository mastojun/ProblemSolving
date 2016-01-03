/**
 * length 가 1000 밖에 안되므로 패턴 찾아서 풀면되는 문제
 *
 * 오답 노트
 *  손으로 좀 해보니 legnth() - 1 이 패턴의 길이 일꺼라고 믿어버림 -_-;;
 */
#include <iostream>
#include <string>
using namespace std;

string next(string prev) {
  string next;
  for (int j = 0; j < prev.length(); j += 2) {
    next += prev[j];
  }
  for (int j = prev.length() % 2 ? prev.length() - 2 : prev.length() - 1; j > 0; j -= 2) {
    next += prev[j];
  }

  return next;
}

int patternLength(string word) {
  string p = word;
  for (int i = 1;;i++) {
    string n = next(p);
    if (n == word) return i;
    p = n;
  }
  return word.length(); //?
}

int main() {
  int X;
  cin >> X;

  string word;
  cin >> word;


  X %= patternLength(word);

  for (int i = 0; i < X; i++) {
    word = next(word);
  }

  cout << word << endl;

  return 0;
}
