/**
 * 문제의 설명대로만 풀면 되는 문제... 인듯 싶으나
 * 부동소수점 연산의 함정이 숨어있는 문제 ㅠㅠ
 **/
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T --> 0) {
        int n, m;
        int score[1001][2];
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++) {
            score[i][0] = score[i][1] = 0;
        }

        for(int i = 0; i < m; i++) {
            int a, b, p, q;
            scanf("%d %d %d %d", &a, &b, &p, &q);
            score[a][0] += p;
            score[a][1] += q;
            score[b][0] += q;
            score[b][1] += p;
        }

        int mini = 1000;
        int Maxi = 0;

        for(int i = 1; i <= n; i++) {
            int S = score[i][0];
            int A = score[i][1];
            int r = 0;
            if(S || A) r = S*S*1. / (S*S + A*A) * 1000 + 1e-16;
            mini = min(mini, r);
            Maxi = max(Maxi, r);
        }

        printf("%d\n%d\n", Maxi, mini);
    }

    return 0;
}

