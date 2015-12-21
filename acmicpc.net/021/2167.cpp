/**
 * 부분합을 이용하는 전형적인 문제인데 한번에 못맞춤
 *
 * 첨엔 문제에 주어지지 않은 cell 들의 최댓값때문에 overflow가 발생한줄 알았는데
 * 알고보니 마지막 if문에 [j = 2]; 라는 코드가 있었드아...아.....
 */
#include <cstdio>

using namespace std;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[300][300];
    int sum[300][300];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
            sum[i][j] = matrix[i][j];
            if (i > 0) sum[i][j] += sum[i - 1][j];
            if (j > 0) sum[i][j] += sum[i][j - 1];
            if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
        }
    }

    int k;
    scanf("%d", &k);
    while (k --> 0) {
        int i, j, x, y;
        scanf("%d %d %d %d", &i, &j, &x, &y);
        int result = sum[x - 1][y - 1];
        if(i > 1) result -= sum[i - 2][y - 1];
        if(j > 1) result -= sum[x - 1][j - 2];
        if(i > 1 && j > 1) result += sum[i - 2][j - 2];

        printf("%d\n", result);
    }

    return 0;
}

