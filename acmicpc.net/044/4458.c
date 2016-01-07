#include <stdio.h>
#include <ctype.h>

int main() {
  int N;
  char str[50];
  scanf("%d ", &N);
  while (gets(str)) {
    printf("%c%s\n", toupper(str[0]), str + 1);
  }

  return 0;
}

