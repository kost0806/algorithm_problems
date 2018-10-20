/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

int T;
int N, M, C;
int c_range;
short honey[10][10];

int _get(short *arr, int size, int idx, int s, int c) {
    if (idx == size) {
        return s;
    }

    int ret = s;
    for (int i = idx; i < size; ++i) {
        if (c + arr[i] <= C)
            ret = max(ret, _get(arr, size, i + 1, s + (arr[i] * arr[i]), c + arr[i]));
    }
    return ret;
}

int get_honey(int l, int c) {
    return _get(&honey[l][c], M, 0, 0, 0);
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d %d", &N, &M, &C);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &honey[i][j]);
            }
        }

        int ret = 0;
        c_range = N - M + 1;
        // select first
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < c_range; ++j) {
                int first = get_honey(i, j);

                // select second
                int second = 0;
                for (int _j = j + M; _j < c_range; ++_j) {
                    second = max(second, get_honey(i, _j));
                }
                for (int _i = i + 1; _i < N; ++_i) {
                    for (int _j = 0; _j < c_range; ++_j) {
                        second = max(second, get_honey(_i, _j));
                    }
                }
                ret = max(ret, first + second);
            }
        }

        printf("#%d %d\n", t, ret);
    }
}