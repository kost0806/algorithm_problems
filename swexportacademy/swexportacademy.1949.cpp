/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
* Kostrian(Minyeong Kim, kost0806)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct BLOCK {
	int x;
	int y;
	int h;
	bool visited;
} BLOCK;

int T, N, K;
BLOCK **map;

int explore(BLOCK start, int length) {
	int ret = length + 1;
	int dret[4] = { 0, };
	int directions[4][2] = { /* UP */{-1, 0}, /* DOWN */{1, 0}, /* LEFT */{0, -1}, /* RIGHT */{0, 1} };

	map[start.x][start.y].visited = true;

	for (int direction = 0; direction < 4; ++direction) {
		int _x = start.x + directions[direction][0];
		int _y = start.y + directions[direction][1];
		if (_x >= 0 && _x < N && _y >= 0 && _y < N) {
			BLOCK& next = map[_x][_y];
			if (!next.visited) {
				if (next.h < start.h) {
					ret = max(ret, explore(next, length + 1));
				}
			}
		}
	}

	map[start.x][start.y].visited = false;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; ++t) {
		string tmp;
		cin >> N;
		cin >> K;
		vector<BLOCK> highest;
		int max_height = 0;

		map = new BLOCK*[N];

		for (int i = 0; i < N; ++i) {
			map[i] = new BLOCK[N];
			for (int j = 0; j < N; ++j) {
				int h;
				cin >> h;
				map[i][j] = { i, j, h, false };
				if (h > max_height) {
					max_height = h;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j].h == max_height)
					highest.push_back(map[i][j]);
			}
		}

		int length = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k <= K; ++k) {
					map[i][j].h -= k;
					for (int hi = 0; hi < highest.size(); ++hi) {
						length = max(length, explore(highest[hi], 0));
					}
					map[i][j].h += k;
				}
			}

		printf("#%d %d\n", t + 1, length);
	}
	return 0;
}