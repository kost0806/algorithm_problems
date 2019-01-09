// https://www.acmicpc.net/problem/1003

#include <cstdio>

using namespace std;

int T;
int cache[41][2];

void construct() {
    // handle 0
    cache[0][0] = 1;
    cache[0][1] = 0;
    // handle 1
    cache[1][0] = 0;
    cache[1][1] = 1;

    for (int i = 2; i <= 40; ++i) {
        cache[i][0] = cache[i - 1][0] + cache[i - 2][0];
        cache[i][1] = cache[i - 1][1] + cache[i - 2][1];
    }
}

int main() {
    scanf("%d", &T);

    construct();

    for (int t = 0; t < T; ++t) {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", cache[n][0], cache[n][1]);
    }
}