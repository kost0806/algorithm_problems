// https://www.acmicpc.net/problem/16493

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int day[21];
int page[21];
int cache[21][201];

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= M; ++i) {
        scanf("%d %d", day + i, page + i);
    }

    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= M; ++i) {
        for (int d = 1; d <= N; ++d) {
            if (d < day[i]) {
                cache[i][d] = cache[i - 1][d];
            }
            else {
                cache[i][d] = max(cache[i - 1][d], cache[i - 1][d - day[i]] + page[i]);
            }
        }
    }
    printf("%d", cache[M][N]);
}
