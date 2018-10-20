#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
bool map[50][50];
bool swipe[50][50];
int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[4] = {0, 1, 0, -1};

int main() {
    memset(swipe, 0, sizeof(swipe));

    scanf("%d %d", &N, &M);

    int d, x, y;
    scanf("%d %d %d", &x, &y, &d);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", map[i] + j);
        }
    }

    bool working = true;
    int _x, _y, _d;
    int rotate_count = 0;
    int ret = 0;
    while (working) {
        if (rotate_count == 4) {
            _d = (d + 2) % 4;
            _x = x + dx[_d];
            _y = y + dy[_d];
            if (map[_x][_y]) {
                working = false;
                break;
            }
            x = _x; y = _y;
            rotate_count = 0;
        }

        if (!swipe[x][y]) {
            swipe[x][y] = true;
            ++ret;
        }

        _d = (d + 3) % 4;
        _x = x + dx[_d];
        _y = y + dy[_d];

        if (!swipe[_x][_y] && !map[_x][_y]) {
            x = _x; y = _y; d = _d;
            rotate_count = 0;
        }
        else {
            d = _d;
            ++rotate_count;
            continue;
        }
    }

    printf("%d", ret);
}