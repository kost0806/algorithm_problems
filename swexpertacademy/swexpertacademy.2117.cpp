/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define _abs(x) (x) < 0 ? -(x) : (x)

int T;
int N, M;
bool map[20][20];
int cost[19 * 19 + 1];

int check_coverage(int x, int y, int c) {
    int count = 0;
    int _c = c - 1;
    for (int i = x - _c; i <= x + _c; ++i) {
        for (int j = y - _c; j <= y + _c; ++j) {
            int dx = _abs(x - i), dy = _abs(y - j);
            if (i >= 0 && i < N && j >= 0 && j < N && dx + dy < c && map[i][j])
                ++count;
        }
    }

    return count;
}

int main() {
    scanf("%d", &T);

    for (int i = 1; i < 19 * 19; ++i) {
        cost[i] = i * i + (i - 1) * (i - 1);
    }

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &map[i][j]);
            }
        }

        int max_serv = 0, max_coverage = 2 * (N - 1);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int c = 1; c <= N + 1; ++c) {
                    int s = check_coverage(i, j, c);
                    int benefit = (s * M) - cost[c];
                    if (benefit >= 0 && s > max_serv) {
                        max_serv = s;
                    }
                }
            }
        }

        printf("#%d %d\n", t, max_serv);
    }
}