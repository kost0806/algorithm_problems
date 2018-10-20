/*
* PROBLEM: https://www.acmicpc.net/problem/14502
* SOLVER: Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
short map[8][8];
bool visit[8][8];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int spread(int x, int y) {
    int ret = 1;
    visit[x][y] = true;

    for (int d = 0; d < 4; ++d) {
        int _x = x + dx[d], _y = y + dy[d];
        if (_x < 0 || _x >= N || _y < 0 || _y >= M || visit[_x][_y])
            continue;
        if (map[_x][_y] == 0) {
            ret += spread(_x, _y);
        }
    }

    return ret;
}

int count_disease() {
    int ret = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 2)
                ret += spread(i, j);
        }
    }
    return ret;
}

int traversal(int min_x, int min_y, int depth) {
    if (depth == 3) {
        return count_disease();
    }

    int ret = INT_MAX;
    for (int i = min_x; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == min_x && j <= min_y)
                continue;
            if (map[i][j] == 0) {
                map[i][j] = 1;
                ret = min(ret, traversal(i, j, depth + 1));
                map[i][j] = 0;
            }
        }
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &M);

    int safe_count = 0, disease_count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%hd", map[i] + j);
            safe_count += (map[i][j] == 0);
            disease_count += (map[i][j] == 2);
        }
    }

    int ret = INT_MAX;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                ret = min(ret, traversal(i, j, 1));
                map[i][j] = 0;
            }
        }
    }

    printf("%d", safe_count - ret + disease_count - 3);
}
