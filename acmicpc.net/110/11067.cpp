/**
 * @url https://www.acmicpc.net/problem/11067
 * @editorial
 *   모노톤길의 특성에 따라, i번째 카페와 i + 1번째 카페는 x, y좌표중 하나는 반드시 똑같다.
 *   x좌표가 커지는 방향으로 진행을 하므로, 가장 먼저 x축을 기준으로 정렬을 진행한다.
 *   모노톤길 특성에 따라 x값이 달라지는 구간에서 y값도 달라지면 성질에 어긋나므로 역순 정렬을 한다.
 *   이때, 입력에는 모든 카페의 좌표가 주어진다고 가정을 해 뒤집기만 하면 된다는 가정을 했다.
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

bool orderByXY(const Point& l, const Point& r) {
    if(l.x < r.x) return true;
    if(l.x > r.x) return false;
    return l.y < r.y;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T --> 0) {
        int n;
        scanf("%d", &n);
        vector<Point> points;
        points.push_back({-1, 0});
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            points.push_back({x, y});
        }
        sort(points.begin(), points.end(), orderByXY);

        for(int i = 1; i <= n; i++) {
            if(points[i - 1].x != points[i].x) {
                int s = i;
                int e = i;
                for(; e <= n; e++) {
                    if(points[s].x != points[e].x) break;
                }
                if(points[i - 1].y != points[s].y) {
                    reverse(points.begin() + s, points.begin() + e);
                }
            }
        }

        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            int p;
            scanf("%d", &p);
            printf("%d %d\n", points[p].x, points[p].y);
        }
    }

    return 0;
}

