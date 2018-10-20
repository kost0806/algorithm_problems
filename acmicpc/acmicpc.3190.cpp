#include <cstdio>
#include <cstring>
#include <deque>
#include <iterator>

using namespace std;

typedef struct snake_body {
    int x, y;
} snake_body;

typedef struct _move {
    int t;
    short d;
} _move;

int N, K, L;
bool map[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
deque<snake_body> snake;
char m[10001];

inline short dir(int d, char c) {
    short _d;
    switch (c) {
        case 'D':
            _d = (d + 1) % 4;
            break;
        case 'L':
            _d = (d + 3) % 4;
            break;
    }
    return _d;
}

bool collision(int x, int y) {
    for (deque<snake_body>::iterator iter = snake.begin(); iter != snake.end(); ++iter) {
        if ((*iter).x == x && (*iter).y == y)
            return true;
    }
    return false;
}

int main() {
    memset(map, 0, sizeof(map));
    memset(m, 0, sizeof(m));
    scanf("%d", &N);
    scanf("%d", &K);

    int x, y;
    for (int i = 0; i < K; ++i ) {
        scanf("%d %d", &x, &y);
        map[x - 1][y - 1] = true;
    }

    scanf("%d", &L);
    short t;
    char tmp;
    for (int i = 0; i < L; ++i) {
        scanf("%hd %c", &t, &tmp);
        m[t] = tmp;
    }

    snake.push_back({0, 0});
    int total_time = 0;
    bool game = true;
    short d = 1;
    while (game) {
        snake_body head = snake.front();
        int _x = head.x + dx[d];
        int _y = head.y + dy[d];
        if (_x < 0 || _x >= N || _y < 0 || _y >= N) {
            game = false;
            break;
        }
        else if (collision(_x, _y)) {
            game = false;
            break;
        }
        else if (map[_x][_y]) {
            map[_x][_y] = false;
            snake.push_front({_x, _y});
        }
        else {
            snake.pop_back();
            snake.push_front({_x, _y});
        }
        ++total_time;
        if (m[total_time] != 0) {
            d = dir(d, m[total_time]);
        }
    }

    printf("%d", total_time + 1);
}