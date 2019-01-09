// https://www.acmicpc.net/problem/2178

#include <cstdio>
#include <cstring>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef struct point {
    int x, y;
    int length;
} point;

int N, M;
bool map[100][100];
bool visit[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs() {
    queue<point> q;
    point start = {0, 0, 1};

    memset(visit, 0, sizeof(visit));

    q.push(start);
    int ret = INT_MAX;
    while (!q.empty()) {
        point current = q.front();
        q.pop();

        if (visit[current.x][current.y])
            continue;

        if (current.x == N - 1 && current.y == M - 1) {
            ret = min(ret, current.length);
            continue;
        }

        visit[current.x][current.y] = true;

        for (int d = 0; d < 4; ++d) {
            int _x = current.x + dx[d], _y = current.y + dy[d];
            if (_x >= N || _x < 0 || _y >= M || _y < 0 || !map[_x][_y] || visit[_x][_y])
                continue;
            q.push({_x, _y, current.length + 1});
        }
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &M);

    memset(map, 0, sizeof(map));
    for (int i = 0; i < N; ++i) {
        char tmp[100];
        scanf("%s", tmp);
        for (int j = 0; j < M; ++j) {
            if (tmp[j] == '1')
                map[i][j] = true;
        }
    }

    printf("%d", bfs());
}