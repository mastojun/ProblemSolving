/**
 * 규칙을 찾으려고 했으나 규칙을 찾지 못해서...
 *
 * 2자리 팰린드롬인경우 AA(K) 일 경우 A*K+A 가 입력한 수 N이 되어야 하므로
 * N/A - 1 이 정수 K가 되야함을 이용해서 두자리가 되는 진법을 알 수 있음
 *
 * 2자리 이상은 위와같은 규칙을 찾기 어려우나, sqrt(N)보단 작을 수 밖에 없으므로 모두 구해보면됨.
 *
 * 속도빠른 솔루션들을 보니 정렬을 따로 하지 않고 숫서대로 찾았네(...)
 *
 * 오답노트
 *  n진법일때는 숫자가 n"이상" 나오면 안되는데 비교문을 if (n < i) 로 해두어서 오답이남...
 *  결국 naive 하게 푼것과 비교했더니... 6에서 다르게 나와서 오류를 발견하게됨..
 */
#include <cstdio>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> result;

void findTowPalindrome(int X) {
  for (int i = 1; i < X; i++) {
    if (X % i) continue;
    int n = X / i - 1;
    if (n <= i) {
      break;
    }
    result.push_back(n);
  }
}

vector<int> number(int num, int base) {
  vector<int> result;
  while (num) {
    result.push_back(num % base);
    num /= base;
  }

  return result;
}

bool isPalindrome(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != nums[nums.size() - i - 1]) return false;
  }
  return true;
}

void findOtherpalindrome(int X) {
  for (long long i = 2; i * i <= X; i++) {
    if (isPalindrome(number(X, i))) {
      result.push_back(i);
    }
  }
}

void solve(int X) {
  findTowPalindrome(X);
  findOtherpalindrome(X);

  sort(result.begin(), result.end());

  for (int i = 0; i < result.size(); i++) {
    printf("%d\n", result[i]);
  }
}

int main() {

  int X;
  scanf("%d", &X);

  solve(X);

  return 0;
}

