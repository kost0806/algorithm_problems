/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

int T, N, X;
short map[20][20];
bool slope[20][20];

int main() {
	//freopen("C:\\Users\\kimmi\\Downloads\\sample_input\\sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t <= T; ++t) {
		scanf("%d %d", &N, &X);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%hd", &map[i][j]);
			}
		}

		int ret = 0;
		// 가로 확인
		memset(slope, 0, sizeof(slope));
		for (int i = 0; i < N; ++i) {
			bool possible = true;
			for (int j = 0; j < N - 1; ++j) {
				if (abs(map[i][j] - map[i][j + 1]) > 1) {
					possible = false;
					break;
				}
				else if (map[i][j] != map[i][j + 1]) {
					if (map[i][j] > map[i][j + 1] && j + X < N) {
						bool check = true;
						short h = map[i][j + 1];
						for (int x = 1; x <= X; ++x) {
							if (slope[i][j + x] || map[i][j + x] != h) {
								check = false;
								break;
							}
						}
						if (check) {
							for (int x = 1; x <= X; ++x) {
								slope[i][j + x] = true;
							}
						}
						else {
							possible = false;
							break;
						}
					}
					else if (map[i][j] < map[i][j + 1] && j - X + 1 >= 0) {
						bool check = true;
						short h = map[i][j];
						for (int x = 0; x < X; ++x) {
							if (slope[i][j - x] || map[i][j - x] != h) {
								check = false;
								break;
							}
						}
						if (check) {
							for (int x = 0; x < X; ++x) {
								slope[i][j - x] = true;
							}
						}
						else {
							possible = false;
							break;
						}
					}
					else {
						possible = false;
						break;
					}
				}
			}
			ret += possible;
		}

		// 세로 확인
		memset(slope, 0, sizeof(slope));
		for (int j = 0; j < N; ++j) {
			bool possible = true;
			for (int i = 0; i < N - 1; ++i) {
				if (abs(map[i][j] - map[i + 1][j]) > 1) {
					possible = false;
					break;
				}
				else  if (map[i][j] != map[i + 1][j]) {
					if (map[i][j] > map[i + 1][j] && i + X < N) {
						bool check = true;
						short h = map[i + 1][j];
						for (int x = 1; x <= X; ++x) {
							if (slope[i + x][j] || map[i + x][j] != h) {
								check = false;
								break;
							}
						}
						if (check) {
							for (int x = 1; x <= X; ++x) {
								slope[i + x][j] = true;
							}
						}
						else {
							possible = false;
							break;
						}
					}
					else if (map[i][j] < map[i + 1][j] && i - X + 1 >= 0) {
						bool check = true;
						short h = map[i][j];
						for (int x = 0; x < X; ++x) {
							if (slope[i - x][j] || map[i - x][j] != h) {
								check = false;
								break;
							}
						}
						if (check) {
							for (int x = 0; x < X; ++x) {
								slope[i - x][j] = true;
							}
						}
						else {
							possible = false;
							break;
						}
					}
					else {
						possible = false;
						break;
					}
				}
			}
			ret += possible;
		}

		printf("#%d %d\n", t, ret);
	}
}