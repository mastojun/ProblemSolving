/**
 * 첫번째 글자만 중요하므로 나머지는 버리고, 배열에 카운트함
 */
#include <cstdio>

using namespace std;

int main() {
  int n;
  int count[26] = {0};
  scanf("%d\n", &n);
  while (n --> 0) {
    char first;
    scanf("%c%*s\n", &first);
    count[first - 'a']++;
  }

  bool hasTeam = false;
  for (int i = 0; i < 26; i++) {
    if (count[i] >= 5) {
      printf("%c", i + 'a');
      hasTeam = true;
    }
  }

  if (!hasTeam) {
    puts("PREDAJA");
  }

  return 0;
}

