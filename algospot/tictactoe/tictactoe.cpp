#include <cstdio>

#include <iostream>
#include <string>

using namespace std;

int C;
char board[3][4];
char cache[20000];

int getStatus() {
  int result = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result *= 3;
      result += board[i][j] == '.' ? 0 : board[i][j] == 'x' ? 1 : 2;
    }
  }
  return result;
}

bool allSame(int sy, int sx, int dy, int dx, char c) {
  for (int i = 0; i < 3; i++) {
    if (board[sy + dy * i][sx + dx * i] != c) return false;
  }
  return true;
}

char getResult() {
  for (int i = 0; i < 3; i++) {
    if (allSame(i, 0, 0, 1, 'x')) return 'x';
    if (allSame(i, 0, 0, 1, 'o')) return 'o';
    if (allSame(0, i, 1, 0, 'x')) return 'x';
    if (allSame(0, i, 1, 0, 'o')) return 'o';
  }
  if (allSame(0, 0, 1, 1, 'x')) return 'x';
  if (allSame(0, 0, 1, 1, 'o')) return 'o';
  if (allSame(0, 2, 1, -1, 'x')) return 'x';
  if (allSame(0, 2, 1, -1, 'o')) return 'o';

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == '.') return 0;
    }
  }
  return 't';
}

char winner(char now) {
  int status = getStatus();

  char& result = cache[status];
  if (result != 0) return result;

  result = getResult();
  if (result != 0) return result;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != '.') continue;
      board[i][j] = now;

      char nextResult = winner(now == 'x' ? 'o' : 'x');
      if (nextResult == now) result = now;
      else if (nextResult == 't' && result != now) result = 't';
      else if (result == 0) result = nextResult;

      board[i][j] = '.';
    }
  }

  return result;
}

char firstPlayer() {
  int cx = 0;
  int co = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 'x') cx++;
      if (board[i][j] == 'o') co++;
    }
  }
  return cx > co ? 'o' : 'x';
}

int main() {
  scanf("%d", &C);
  while (C --> 0) {
    for (int i = 0; i < 3; i++) {
      scanf("%s", board[i]);
    }
    char result = winner(firstPlayer());
    if (result == 't') puts("TIE");
    else printf("%c\n", result);
  }

  return 0;
}

