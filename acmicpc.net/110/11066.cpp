/**
 * @url https://www.acmicpc.net/submit/11066/1029139
 * @editorial
 *   dynamic programming 문제.
 *   solve(s, e)가 s부터 e까지지 합치는데 드는 비용을 반환하며, s 와 e가 결정되면 값은 변하지 않으므로 dp로 풀 수 있음.
 *   s 부터 e까지 합치는데 드는 비용은 (s .. i 를 합치는데 드는 비용) + ( i + 1 .. e 를 합치는데 드는 비용) + (두 묶음을 합치는데 드는 비용) 임을 이용하서 풀 수있다.
 *
 *   여기서 두 묶음을 합치는데 드는 비용 역시 dp로 한번에 계산하는게 좋으며, 그렇지 않으면 시간복잡도가 O(n^4)가 된다. 이 솔루션은 O(n^3)
 */
#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int pages[501];
int dp[500][500];

int solve(int s, int e) {

    if(s >= e) return 0;

    int& result = dp[s][e];
    if(result != -1) return result;

    result = INT_MAX;
    for(int i = s; i <= e; i++) {
        result = min(result, solve(s, i) + solve(i + 1, e) + pages[e] - pages[s - 1]);
    }

    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T --> 0) {
        int K;
        scanf("%d", &K);
        for(int i = 1; i <= K; i++) {
            scanf("%d", pages + i);
        }
        for(int i = 1; i <= K; i++) {
            pages[i] += pages[i - 1];
        }

        memset(dp, -1, sizeof(dp));

        printf("%d\n", solve(1, K));
    }

    return 0;
}

