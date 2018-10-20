/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo
* Kostrian(Minyeong Kim, kost0806)
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct point {
    int x, y;
} point;

int T;
int N, W, H;
int **blocks;
int delta[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // up, down, left, right

void copy_arr(int** src, int** dest) {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            dest[i][j] = src[i][j];
        }
    }
}

int count_block() {
    int block_count = 0;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (!blocks[y][x] == 0)
                ++block_count;
        }
    }
    return  block_count;
}

void break_block(int x, int y) {
    if (blocks[y][x] == 0)
        return;
    if (blocks[y][x] == 1) {
        blocks[y][x] = 0;
        return;
    }
    int range = blocks[y][x] - 1;
    blocks[y][x] = 0;
    for (int d = 0; d < 4; ++d) {
        if (delta[d][0] != 0) {
            for (int dx = delta[d][0]; x + dx < W && x + dx >= 0 && abs(dx) <= range; dx += delta[d][0]) {
                break_block(x + dx, y);
            }
        }
        else {
            for (int dy = delta[d][1]; y + dy < H && y + dy >= 0 && abs(dy) <= range; dy += delta[d][1]) {
                break_block(x, y + dy);
            }
        }
    }
}

void rearrange() {
    int tmp_y;
    for (int y = H - 2; y >= 0; --y) {
        for (int x = 0; x < W; ++x) {
            if (blocks[y][x] != 0) {
                tmp_y = y;
                while (tmp_y + 1 < H && blocks[tmp_y + 1][x] == 0)
                    ++tmp_y;
                if (tmp_y != y) {
                    blocks[tmp_y][x] = blocks[y][x];
                    blocks[y][x] = 0;
                }
            }
        }
    }
}

int break_blocks(int x, int n) {
    int start_y = 0;
    while (start_y < H && blocks[start_y][x] == 0)
        ++start_y;
    if (start_y < H)
        break_block(x, start_y);
    rearrange();

    if (n == 0) {
        return count_block();
    }

    int ret = count_block();
    int **tmp_blocks = new int*[H];
    for (int i = 0; i < H; ++i) {
        tmp_blocks[i] = new int[W];
    }
    for (int next = 0; next < W; ++next ) {
        copy_arr(blocks, tmp_blocks);
        ret = min(ret, break_blocks(next, n - 1));
        copy_arr(tmp_blocks, blocks);
    }

    free(tmp_blocks);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N >> W >> H;
        blocks = new int*[H];
        for (int y = 0; y < H; ++y) {
            blocks[y] = new int[W];
            for (int x = 0; x < W; ++x) {
                cin >> blocks[y][x];
            }
        }

        int **tmp_blocks = new int*[H];
        for (int i = 0; i < H; ++i) {
            tmp_blocks[i] = new int[W];
        }
        int remain = count_block();
        for (int x = 0; x < W; ++x) {
            copy_arr(blocks, tmp_blocks);
            remain = min(remain, break_blocks(x, N - 1));
            copy_arr(tmp_blocks, blocks);
        }
        free(tmp_blocks);

        int ret = remain;

        cout << "#" << t << " " << ret << "\n";
    }

    return 0;
}