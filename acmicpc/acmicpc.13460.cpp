#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_RET 11

using namespace std;

int N, M;
char map[10][10];

int move(int d) {
    bool r_end = false, b_end = false;
    if (d == 0) {
        for (int j = 1; j < M - 1; ++j) {
            for (int i = 0; i < N; ++i) {
                if (map[i][j] == 'R' || map[i][j] == 'B') {
                    int _i = i;
                    while (_i > 0 && (map[_i - 1][j] == '.' || map[_i - 1][j] == 'O')) {
                        --_i;
                        if (map[_i][j] == 'O')
                            break;
                    }
                    if (_i == i)
                        continue;
                    if (map[_i][j] == '.') {
                        map[_i][j] = map[i][j];
                        map[i][j] = '.';
                    }
                    else if (map[_i][j] == 'O') {
                        if (map[i][j] == 'R')
                            r_end = true;
                        else
                            b_end = true;
                        map[i][j] = '.';
                    }
                }
            }
        }
    }
    else if (d == 1) {
        for (int j = 1; j < M - 1; ++j) {
            for (int i = N - 1; i >= 0; --i) {
                if (map[i][j] == 'R' || map[i][j] == 'B') {
                    int _i = i;
                    while (_i < N - 1 && (map[_i + 1][j] == '.' || map[_i + 1][j] == 'O')) {
                        ++_i;
                        if (map[_i][j] == 'O')
                            break;
                    }
                    if (_i == i)
                        continue;
                    if (map[_i][j] == '.') {
                        map[_i][j] = map[i][j];
                        map[i][j] = '.';
                    }
                    else if (map[_i][j] == 'O') {
                        if (map[i][j] == 'R')
                            r_end = true;
                        else
                            b_end = true;
                        map[i][j] = '.';
                    }
                }
            }
        }
    }
    else if (d == 2) {
        for (int i = 1; i < N - 1; ++i) {
            for (int j = 0; j < M; ++j) {
                if (map[i][j] == 'R' || map[i][j] == 'B') {
                    int _j = j;
                    while (_j > 0 && (map[i][_j - 1] == '.' || map[i][_j - 1] == 'O')) {
                        --_j;
                        if (map[i][_j] == 'O')
                            break;
                    }
                    if (_j == j)
                        continue;
                    if (map[i][_j] == '.') {
                        map[i][_j] = map[i][j];
                        map[i][j] = '.';
                    }
                    else if (map[i][_j] == 'O') {
                        if (map[i][j] == 'R')
                            r_end = true;
                        else
                            b_end = true;
                        map[i][j] = '.';
                    }
                }
            }
        }
    }
    else {
        for (int i = 1; i < N - 1; ++i) {
            for (int j = M - 1; j >= 0; --j) {
                if (map[i][j] == 'R' || map[i][j] == 'B') {
                    int _j = j;
                    while (_j < M - 1 && (map[i][_j + 1] == '.' || map[i][_j + 1] == 'O')) {
                        ++_j;
                        if (map[i][_j] == 'O')
                            break;
                    }
                    if (_j == j)
                        continue;
                    if (map[i][_j] == '.') {
                        map[i][_j] = map[i][j];
                        map[i][j] = '.';
                    }
                    else if (map[i][_j] == 'O') {
                        if (map[i][j] == 'R')
                            r_end = true;
                        else
                            b_end = true;
                        map[i][j] = '.';
                    }
                }
            }
        }
    }
    return 2 * b_end + 1 * r_end;
}

int travel(int d, int depth) {
    if (depth == 11)
        return MAX_RET;

    int flag = move(d);
    if (flag >= 2) {
        return MAX_RET;
    }
    else if (flag == 1) {
        return depth;
    }

    int ret = MAX_RET;
    char tmp[10][10];
    for (int _d = 0; _d < 4; ++_d) {
        if ((d == 0 && _d == 1) ||
                (d == 1 && _d == 0) ||
                (d == 2 && _d == 3) ||
                (d == 3 && _d == 2))
            continue;
        memcpy(tmp, map, sizeof(map));
        ret = min(ret, travel(_d, depth + 1));
        memcpy(map, tmp, sizeof(map));
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%c", map[i] + j);
            if (map[i][j] == '\n')
                --j;
        }
    }

    int ret = MAX_RET;
    char tmp[10][10];
    for (int d = 0; d < 4; ++d) {
        memcpy(tmp, map, sizeof(map));
        int _ret = travel(d, 1);
        ret = min(ret, _ret);
        memcpy(map, tmp, sizeof(map));
    }
    if (ret == 11)
        ret = -1;
    printf("%d\n", ret);
}