/**
 * 문제에 있는 그림만 보고는
 * f(n) = f(n - 2) * 3 + f(n - 4) * 2
 * 로 착각 하기 쉬운 문제 (3년전에도 그렇게 착각해서 틀렸음 -_-;)
 * 짝수의 배수만큼은 이어진 블럭을 만들 수 있어서 아래와 같이 짜야한다.
 *
 * 그래도 틀렸던 히스토리
 *  코딩을 잘못해서 (solve(n-i)를 solve(n-2)로 함) int 로는 안되고 long long으로 되는줄 알고 제출했다가 fail
 *  코딩 잘못한거 발견하고 n - 2 로 수정후 long long을 int로 바꾸었는데 fail
 *  printf("%lld\n", solve(n)) 이 문제여서 %d로 고쳐서 accepted!
 */
#include <cstdio>
#include <cstring>

using namespace std;

int dp[31];

int solve(int n) {
    if(n < 0) return 0;
    if(n == 0) return 1;

    int& result = dp[n];

    if(result != -1) return result;

    result = solve(n - 2);

    for(int i = 2; i <= n; i += 2) {
        result += solve(n - i) * 2;
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    memset(dp, -1, sizeof(dp));

    printf("%d\n", solve(n));

    return 0;
}

