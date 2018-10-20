#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef struct point {
    int x, y;
} point;

int N, M;
short map[8][8];
bool watch[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int times[6] = {0, 4, 2, 4, 4, 1};
int d_dir[6][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 2, 0, 0}, {0, 1, 0, 0}, {0, 1, 3, 0}, {0, 1, 2, 3}};
int c_dir[6] = {0, 1, 2, 2, 3, 4};

vector<point> cctv;

int count_dead() {
    int ret = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 0 && !watch[i][j])
                ++ret;
        }
    }

    return ret;
}

int traversal(int idx) {
    if (idx == cctv.size()) {
        return count_dead();
    }

    int ret = INT_MAX;
    point curr_pos = cctv[idx];
    short curr = map[curr_pos.x][curr_pos.y];
    bool tmp_watch[8][8];
    for (int d = 0; d < times[curr]; ++d) {
        int _x, _y;
        memcpy(tmp_watch, watch, sizeof(watch));
        for (int i = 0; i < c_dir[curr]; ++i) {
            _x = curr_pos.x, _y = curr_pos.y;
            while (true) {
                _x += dx[(d + d_dir[curr][i]) % 4];
                _y += dy[(d + d_dir[curr][i]) % 4];
                if (_x < 0 || _x >= N || _y < 0 || _y >= M || map[_x][_y] == 6) {
                    break;
                }
                watch[_x][_y] = true;
            }
        }
        ret = min(ret, traversal(idx + 1));
        memcpy(watch, tmp_watch, sizeof(watch));
    }

    return ret;
}

int main() {
    memset(watch, 0, sizeof(watch));

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%hd", map[i] + j);
            if (map[i][j] >= 1 && map[i][j] <= 5)
                cctv.push_back({i, j});
        }
    }

    int ret = traversal(0);
    printf("%d", ret);
}