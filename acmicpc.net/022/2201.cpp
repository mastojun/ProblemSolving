/**
 * K의 숫자가 너무 커서 어려운 문제로 생각했으나 생각보다 쉬운문제
 * 이친수를 써 내려가면 규칙성이 보이는데,
 * 자릿수가 올라가는게 피보나치 수열을 이루고 있으므로 이를 이용하여 풀 수 있음
 *
 * 출력도 앞자리부터 출력을 하면 되므로 별도의 저장공간도 필요 없음
 * 문제를 풀기 전에 10^18 의 숫자가 되는 피보나치 수열이 몇번째인지 부터 구해야 했음.
 */
#include <cstdio>
#include <cstring>

using namespace std;

long long sum[88] = {1, 1};

int main() {

    for (int i = 2; i < 88; i++) {
        sum[i] = sum[i - 1] + sum[i - 2];
    }

    long long K;
    scanf("%lld", &K);

    bool print = false;
    for (int i = 86; i > 0; i--) {
        if (sum[i + 1] > K && K >= sum[i]) {
            print = true;
            putchar('1');
            K -= sum[i];
        } else {
            if (print) putchar('0');
        }
    }
    putchar('\n');

    return 0;
}

