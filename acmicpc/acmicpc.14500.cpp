/*
* PROBLEM : https://www.acmicpc.net/problem/14500
* SOLVER : Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
short map[500][500];
bool visit[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int s_block[4][4][2] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}}, {{0, 0}, {1, 0}, {2, 0}, {1, 1}}, {{0, 0}, {0, 1}, {0, 2}, {-1, 1}}, {{0, 0}, {1, 0}, {2, 0}, {1, -1}}};

int traversal(int x, int y, int depth, int s) {
    if (depth == 4)
        return s;

    int ret = 0;
    for (int d = 0; d < 4; ++d) {
        int _x = x + dx[d], _y = y + dy[d];
        if (_x < 0 || _y < 0 || _x >= N || _y >= M || visit[_x][_y])
            continue;
        visit[_x][_y] = true;
        ret = max(ret, traversal(_x, _y, depth + 1, s + map[_x][_y]));
        visit[_x][_y] = false;
    }

    return ret;
}

int check_sblock(int x, int y) {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        int mid_sum = 0;
        for (int d = 0; d < 4; ++d) {
            int _x = x + s_block[i][d][0];
            int _y = y + s_block[i][d][1];
            if (_x >= N || _y >= M)
                break;
            mid_sum += map[_x][_y];
        }
        ret = max(ret, mid_sum);
    }

    return ret;
}

int solve() {
    int ret = 0;
    for (int x = 0; x < N - 1; ++x) {
        for (int y = 0; y < M - 1; ++y) {
            visit[x][y] = true;
            ret = max(ret, traversal(x, y, 0, 0));
            visit[x][y] = false;
            ret = max(ret, check_sblock(x, y));
        }
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%hd", map[i] + j);
        }
    }
    int ret = solve();
    printf("%d", ret);
}