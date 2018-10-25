/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <cstring>

using namespace std;

typedef struct tunnel {
    short type; // 1: +, 2: |, 3: -, 4: ㄴ, 5: r, 6: ㄱ, 7: J, 0: blank
    bool visit;
} tunnel;

int T;
int N, M, R, C, L;
tunnel map[50][50];
int dx[4] = {-1, 1, 0, 0}; // up down left right
int dy[4] = {0, 0, -1, 1};
bool from[4][7] = {
        /* Before: UP */ {true, true, false, false, true, true, false},
        /* Before: DOWN */ {true, true, false, true, false, false, true},
        /* Before: LEFT */ {true, false, true, true, true, false, false},
        /* Before: RIGHT */ {true, false, true, false, false, true, true}
};
bool to[7][4] = {
        // 1: +, 2: |, 3: -, 4: ㄴ, 5: r, 6: ㄱ, 7: J, 0: blank
        {true, true, true, true},
        {true, true, false, false},
        {false, false, true, true},
        {true, false, false, true},
        {false, true, false, true},
        {false, true, true, false},
        {true, false, true, false}
};
void visit(int r, int c, int d, int l);

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

        memset(map, 0, sizeof(map));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                short tmp;
                scanf("%hd", &tmp);
                map[i][j] = {tmp, false};
            }
        }

        visit(R, C, -1, L);

        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (map[i][j].visit)
                    ++ret;
            }
        }

        printf("#%d %d\n", t, ret);
    }
}

void visit(int r, int c, int d, int l) {
    if (r >= N && r < 0 && c >= M && c < 0) {
        return;
    }

    if (d != -1 && !from[d][map[r][c].type - 1]) {
        return;
    }

    if (l <= 0) {
        return;
    }

    if (map[r][c].type == 0) {
        return;
    }

    map[r][c].visit = true;

    for (int _d = 0; _d < 4; ++_d) {
        int _r = r + dx[_d], _c = c + dy[_d];
        if (_r < N && _r >= 0 && _c < M && _r >= 0 && to[map[r][c].type - 1][_d]) {
            if ((d == 0 && _d == 1) ||
                    (d == 1 && _d == 0) ||
                    (d == 3 && _d == 2) ||
                    (d == 2 && _d == 3))
                continue;
            visit(_r, _c, _d, l - 1);
        }
    }
}