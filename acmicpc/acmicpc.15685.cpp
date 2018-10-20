#include <cstdio>
#include <iterator>
#include <cstring>

#define X_BOUND 101
#define Y_BOUND 101

using namespace std;

int N;
int dragon[1025];
bool map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    memset(map, 0, sizeof(map));
    scanf("%d", &N);

    int x, y, d, g;
    for (int n = 0; n < N; ++n) {
        scanf("%d %d %d %d", &x, &y, &d, &g);

        int length = 0;
        dragon[length++] = d;

        bool is_end = false;
        for (int _g = 1; _g <= g; ++_g) {
            for (int i = length - 1; i >= 0; --i) {
                int _d = (dragon[i] + 1) % 4;
                dragon[length++] = _d;
            }
        }

        // move dragon to map
        int _x = x, _y = y;
        map[x][y] = true;
        for (int i = 0; i < length; ++i) {
            _x += dx[dragon[i]]; _y += dy[dragon[i]];
            map[_x][_y] = true;
        }
    }

    int ret = 0;
    for (int i = 0; i < X_BOUND; ++i) {
        for (int j = 0; j < Y_BOUND; ++j) {
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
                ++ret;
        }
    }

    printf("%d", ret);
}