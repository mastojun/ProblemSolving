/**
 * 솔루션 읽은 후 수정함.
 * 기존 코드는 log(n*sqrt(s) + s) 수정된건 log(s*log s)
 *
 * 학생수가 s 인 학교의 수를 students[s] 에 저장을 하고, 가능한 팀원의 수(1 ~ max S) 에 대해서
 * 나누어 떨어지는 학교가 몇개 있는지를 세는 방식.
 * D명으로 나누어 떨어지는 학교의 수는 students[D] + students[D * 1] + students[D * 2] + ... + students[D * k], (단 D * k <= max S)
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int students[2000001];

int main() {
  int N;
  int maxStudent = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int student;
    scanf("%d", &student);
    students[student]++;
    maxStudent = max(maxStudent, student);
  }

  long long result = 0;

  for (int i = 1; i <= maxStudent; i++) {
    int school = 0;
    for (int j = 1; i * j <= maxStudent; j++) {
      school += students[j * i];
    }
    if (school > 1) result = max(result, school * 1ll * i);
  }

  printf("%lld\n", result);

  return 0;
}

