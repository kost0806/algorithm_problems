/*
* https://www.acmicpc.net/problem/13458
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <cmath>

using namespace std;

int N, B, C;
int room[1000001];

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", room + i);
    }

    scanf("%d %d", &B, &C);

    long long ret = 0;
    for (int i = 0; i < N; ++i) {
        ++ret;
        room[i] -= B;
        if (room[i] > 0) {
            if (room[i] % C == 0)
                ret += room[i] / C;
            else
                ret += room[i] / C + 1;
        }
    }

    printf("%lld\n", ret);
}