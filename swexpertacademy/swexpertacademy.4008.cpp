/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <climits>

#define max(x, y) (x) > (y) ? (x) : (y)
#define min(x, y) (x) < (y) ? (x) : (y)

using namespace std;

int T, N;
int num[12];
int op[4];

int cal_max(int idx, int result) {
    if (idx == N) {
        return result;
    }

    int max_val = INT_MIN;
    if (op[0] > 0) {
        --op[0];
        max_val = max(max_val, cal_max(idx + 1, result + num[idx]));
        ++op[0];
    }
    if (op[1] > 0) {
        --op[1];
        max_val = max(max_val, cal_max(idx + 1, result - num[idx]));
        ++op[1];
    }
    if (op[2] > 0) {
        --op[2];
        max_val = max(max_val, cal_max(idx + 1, result * num[idx]));
        ++op[2];
    }
    if (op[3] > 0) {
        --op[3];
        max_val = max(max_val, cal_max(idx + 1, result / num[idx]));
        ++op[3];
    }

    return max_val;
}

int cal_min(int idx, int result) {
    if (idx == N) {
        return result;
    }

    int min_val = INT_MAX;
    if (op[0] > 0) {
        --op[0];
        min_val = min(min_val, cal_min(idx + 1, result + num[idx]));
        ++op[0];
    }
    if (op[1] > 0) {
        --op[1];
        min_val = min(min_val, cal_min(idx + 1, result - num[idx]));
        ++op[1];
    }
    if (op[2] > 0) {
        --op[2];
        min_val = min(min_val, cal_min(idx + 1, result * num[idx]));
        ++op[2];
    }
    if (op[3] > 0) {
        --op[3];
        min_val = min(min_val, cal_min(idx + 1, result / num[idx]));
        ++op[3];
    }

    return min_val;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        scanf("%d %d %d %d", op, op + 1, op + 2, op + 3);

        for (int i = 0; i < N; ++i) {
            scanf("%d", num + i);
        }

        int M = cal_max(1, num[0]);
        int m = cal_min(1, num[0]);
        int ret = M - m;

        printf("#%d %d\n", t, ret);
    }
}