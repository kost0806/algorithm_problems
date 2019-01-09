// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWS2h6AKBCoDFAVT

#include <cstdio>

using namespace std;

int T, N;
int h[50000];

int mountain() {
    int up = 0, down = 0, is_up = h[0] < h[1];
    int i = 1;
    int ret = 0;
    while (i < N) {
        if (is_up && h[i - 1] < h[i]) {
            ++up;
        }
        else if (!is_up && h[i - 1] < h[i]) {
            is_up = true;
            ret += up * down;
            up = 1; down = 0;
        }
        else if (!is_up && h[i - 1] > h[i]) {
            ++down;
        }
        else {
            is_up = false;
            ++down;
        }
        ++i;
    }
    return ret + up * down;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", h + i);
        }

        int ret = mountain();
        printf("#%d %d\n", t, ret);
    }
}