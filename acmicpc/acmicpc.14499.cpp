/*
* https://www.acmicpc.net/problem/14499
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <cstring>

using namespace std;

int N, M, X, Y, K;
short map[20][20];
short dice[6] = {0, 5, 2, 3, 1, 4}; // 상 하 동 서 북 남
short value[6];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void rotate(int k) {
    short tmp_dice[6];
    memcpy(tmp_dice, dice, sizeof(dice));
    switch (k) {
        case 0: // 동
            dice[0] = tmp_dice[3];
            dice[1] = tmp_dice[2];
            dice[2] = tmp_dice[0];
            dice[3] = tmp_dice[1];
            break;
        case 1: // 서
            dice[0] = tmp_dice[2];
            dice[1] = tmp_dice[3];
            dice[2] = tmp_dice[1];
            dice[3] = tmp_dice[0];
            break;
        case 2: // 북
            dice[0] = tmp_dice[5];
            dice[1] = tmp_dice[4];
            dice[4] = tmp_dice[0];
            dice[5] = tmp_dice[1];
            break;
        case 3: // 남
            dice[0] = tmp_dice[4];
            dice[1] = tmp_dice[5];
            dice[4] = tmp_dice[1];
            dice[5] = tmp_dice[0];
            break;
    }
}

int main() {
    memset(value, 0, sizeof(value));

    scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%hd", &map[i][j]);
        }
    }

    int x = X, y = Y, _x, _y;
    for (int i = 0; i < K; ++i) {
        int k;
        scanf("%d", &k);

        --k;
        _x = x + dx[k];
        _y = y + dy[k];
        if (_x < 0 || _x >= N || _y < 0 || _y >= M)
            continue;
        rotate(k);
        if (map[_x][_y] == 0) {
            map[_x][_y] = value[dice[1]];
        }
        else {
            value[dice[1]] = map[_x][_y];
            map[_x][_y] = 0;
        }

        printf("%d\n", value[dice[0]]);

        x = _x; y = _y;
    }
}