/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
* Kostrian(Minyeong Kim, kost0806)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int T, N;
short blocks[100][100];
short cache[4][100][100];
short dx[4] = {-1, 1, 0, 0};
short dy[4] = {0, 0, -1, 1};
short w_1[5][2];
short w_2[5][2];
int d_table[5][4] = {{1, 3, 0, 2}, {3, 0, 1, 2}, {2, 0, 3, 1}, {1, 2, 3, 0}, {1, 0, 3, 2}};


int run(int _x, int _y, int _d) {
    if (blocks[_x][_y] != 0) {
        cache[_d][_x][_y] = 0;
        return 0;
    }

    int _next_x = _x + dx[_d], _next_y =  _y + dy[_d];
    if (_next_x >= 0 && _next_x < N && _next_y >= 0 && _next_y < N && blocks[_next_x][_next_y] == 0) {
        int next = cache[_d][_next_x][_next_y];
        if (next != -1) {
            cache[_d][_x][_y] = next;
            return next;
        }
    }

    bool isEnd = false;
    int x = _x, y = _y, d = _d;
    int count = 0;
    while (!isEnd) {
        if (x >= 0 && x < N && y >= 0 && y < N) {
            short b = blocks[x][y];
            if (b == 0) {
                x += dx[d]; y += dy[d];
            } else if (b >= 1 && b <= 5) {
                d = d_table[b - 1][d];
                x += dx[d]; y += dy[d];
                ++count;
            } else if (b >= 6) {
                if (w_1[b - 6][0] == x && w_1[b - 6][1] == y) {
                    x = w_2[b - 6][0]; y = w_2[b - 6][1];
                }
                else {
                    x = w_1[b - 6][0]; y = w_1[b - 6][1];
                }
                x += dx[d]; y += dy[d];
            } else if (b == -1) {
                isEnd = true;
            }
        }
        else {
            d = d_table[4][d];
            x += dx[d]; y += dy[d];
            ++count;
        }

        if (x == _x && y == _y) {
            isEnd = true;
        }
    }

    cache[_d][_x][_y] = count;
    return count;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);

        for (int i = 0; i < 5; ++i) {
            w_1[i][0] = -1; w_1[i][1] = -1;
            w_2[i][0] = -1; w_2[i][1] = -1;
        }

        for (short i = 0; i < N; ++i) {
            for (short j = 0; j < N; ++j) {
                scanf("%hd", &blocks[i][j]);
                if (blocks[i][j] > 5) {
                    if (w_1[blocks[i][j] - 6][0] == -1) {
                        w_1[blocks[i][j] - 6][0] = i;
                        w_1[blocks[i][j] - 6][1] = j;
                    }
                    else {
                        w_2[blocks[i][j] - 6][0] = i;
                        w_2[blocks[i][j] - 6][1] = j;
                    }
                    for (int d = 0; d < 4; ++d) {
                        cache[d][i][j] = -1;
                    }
                }
            }
        }

        int ret = 0;
        // UP
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                ret = max(ret, run(x, y, 0));
            }
        }

        // DOWN
        for (int x = N - 1; x >= 0; --x) {
            for (int y = 0; y < N; ++y) {
                ret = max(ret, run(x, y, 1));
            }
        }

        // LEFT
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                ret = max(ret, run(x, y, 2));
            }
        }
        // RIGHT
        for (int x = 0; x < N; ++x) {
            for (int y = N - 1; y >= 0; --y) {
                ret = max(ret, run(x, y, 3));
            }
        }

        printf("#%d %d\n", t, ret);
    }

    return 0;
}