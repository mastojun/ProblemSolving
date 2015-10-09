/**
 * @editorial
 *   1. 왼쪽/오른쪽으로 떨어지는 개미의 수는 처음 주어진 방향의 개미의 수와 같음.
 *   2. 아무리 충돌이 많이 일어나도 처음 주어진 개미끼리의 상대적 순서는 바뀌지 않음.
 *   3. 따라서, 왼쪽으로 떨어지는 개미가 3마리 라면 처음 주어진 개미 순서의 맨 왼쪽 3마리가 해당됨.
 *   4. 왼쪽으로 떨어지는 개미의 시간은 처음 주어진 왼쪽 방향의 개미가 떨어지는 시간과 동일함.
 *   5. 따라서, 왼쪽으로 떨어지는 개미가 3마리이면 처음 왼쪽 방향으로 향한 개미가 충돌이 없다고 했을경우 떨어지는 시간과 동일함.
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Ant {
    int pos;
    int id;
    bool isLeft;

    Ant(int pos, bool isLeft) {
        this->pos = pos;
        this->isLeft = isLeft;
    }

    bool operator<(const Ant& right) const{
        if(pos == right.pos) return id < right.id;
        return pos < right.pos;
    }
};

int L, N, k;
vector<Ant> ants;

void input() {
    scanf("%d %d %d", &N, &L, &k);

    vector<int> ids;
    ants.clear();
    for(int i = 0; i < N; i++) {
        int pos, id;
        scanf("%d %d", &pos, &id);
        ids.push_back(id);
        if(id < 0) {
            ants.push_back(Ant(pos, true));
        } else {
            ants.push_back(Ant(L - pos, false));
        }
    }

    int idx = 0;
    for(auto& ant : ants) {
        if(ant.isLeft) ant.id = ids[idx++];
    }
    for(auto& ant : ants) {
        if(!ant.isLeft) ant.id = ids[idx++];
    }
}

int solve() {
    sort(ants.begin(), ants.end());
    return ants[k - 1].id;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T --> 0) {
        input();
        printf("%d\n", solve());
    }

    return 0;
}
