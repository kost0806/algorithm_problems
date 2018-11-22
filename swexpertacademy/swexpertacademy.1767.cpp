// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf

#include <cstdio>
#include <climits>
#include <cstring>

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) > (b) ? (b) : (a)

using namespace std;

int T, N, num_core;
int map[12][12];
int cores[12][2];
int min_length;
int curr_length;
int max_connection;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int check(int idx, int connection) {
    if (idx == num_core) {
        if (connection > max_connection) {
            max_connection = connection;
            min_length = curr_length;
        }
        else if (connection == max_connection) {
            min_length = min(min_length, curr_length);
        }
        return connection;
    }

    int ret = connection;
    int check_count = 0;
    for (int d = 0; d < 4; ++d) {
        int tmp_map[12][12], tmp_length = curr_length;
        memcpy(tmp_map, map, sizeof(map));
        int _x = cores[idx][0] + dx[d], _y = cores[idx][1] + dy[d];
        while (_x >= 0 && _x < N && _y >= 0 && _y < N && map[_x][_y] == 0) {
            map[_x][_y] = 2;
            ++curr_length;
            _x += dx[d], _y += dy[d];
        }
        if (_x < 0 || _x >= N || _y < 0 || _y >= N) {
            ret = max(ret, check(idx + 1, connection + 1));
            ++check_count;
        }
        memcpy(map, tmp_map, sizeof(map));
        curr_length = tmp_length;
    }
    if (check_count == 0)
        ret = max(ret, check(idx + 1, connection));

    return ret;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);

        num_core = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", map[i] + j);

                if (i != 0 && i != N - 1 && j != 0 && j != N - 1 && map[i][j] == 1) {
                    cores[num_core][0] = i;
                    cores[num_core][1] = j;
                    ++num_core;
                }
            }
        }

        min_length = INT_MAX;
        max_connection = INT_MIN;
        curr_length = 0;
        check(0, 0);
        printf("#%d %d\n", t, min_length);
    }
}