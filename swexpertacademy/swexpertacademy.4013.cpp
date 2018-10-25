/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>

#pragma warning(disable:4996)

using namespace std;

int T, K;
bool magnet[4][8];
int top[4];

void rotate(int idx, int r) {
	int _tmp_rotate[4] = { 0, 0, 0, 0 };
	int _rotate_direction = r * -1;
	for (int i = idx - 1; i >= 0; --i, _rotate_direction *= -1) {
		if (magnet[i + 1][(top[i + 1] + 6) % 8] != magnet[i][(top[i] + 2) % 8])
			_tmp_rotate[i] = _rotate_direction;
		else
			break;
	}

	_tmp_rotate[idx] = r;

	_rotate_direction = r * -1;
	for (int i = idx + 1; i < 4; ++i, _rotate_direction *= -1) {
		if (magnet[i - 1][(top[i - 1] + 2) % 8] != magnet[i][(top[i] + 6) % 8])
			_tmp_rotate[i] = _rotate_direction;
		else
			break;
	}

	for (int i = 0; i < 4; ++i) {
		top[i] -= (_tmp_rotate[i] - 8);
		top[i] %= 8;
	}
}

int main() {
	scanf("%d", &T);

	for (int t = 1; t <= T; ++t) {
		scanf("%d", &K);

		for (int i = 0; i < 4; ++i) {
			top[i] = 0;
			for (int j = 0; j < 8; ++j) {
				scanf("%d", &magnet[i][j]);
			}
		}

		for (int k = 0; k < K; ++k) {
			int idx, r;
			scanf("%d %d", &idx, &r);

			rotate(idx - 1, r);
		}

		int ret = 0;
		int tmp = 1;
		for (int i = 0; i < 4; ++i, tmp *= 2) {
			ret += magnet[i][top[i]] * tmp;
		}

		printf("#%d %d\n", t, ret);
	}
}