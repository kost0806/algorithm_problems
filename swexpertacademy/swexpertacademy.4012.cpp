/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeUtVakTMDFAVH
* Kostrian(Minyeong Kim, kost0806)
*/

#include <cstdio>
#include <vector>
#include<cstdlib>

using namespace std;

int T, N, **S;

int diff(vector<bool> A, int index, int n) {
	int ret = 20001;

	if (n == 0) {
		int sumA = 0, sumB = 0;
		vector<int> A_choosen;
		vector<int> B_choosen;
		for (int i = 0; i < N; ++i) {
			if (A[i])
				A_choosen.push_back(i);
			else
				B_choosen.push_back(i);
		}
		for (int i = 0; i < N / 2; ++i) {
			int food = A_choosen[i];
			for (int j = 0; j < N / 2; ++j) {
				if (!(i == j)) {
					sumA += S[food][A_choosen[j]];
				}
			}
		}
		for (int i = 0; i < N / 2; ++i) {
			int food = B_choosen[i];
			for (int j = 0; j < N / 2; ++j) {
				if (!(i == j)) {
					sumB += S[food][B_choosen[j]];
				}
			}
		}


		return abs(sumA - sumB);
	}

	for (int i = 0; i < N - index - n + 1; ++i) {
		A[index + i] = true;
		ret = min(ret, diff(A, index + i + 1, n - 1));
		A[index + i] = false;
	}

	return ret;
}

int main() {
	int A, remain;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d", &N);

		S = (int **)malloc(sizeof(int *) * N);
		for (int i = 0; i < N; ++i) {
			S[i] = (int *)malloc(sizeof(int) * N);
			for (int j = 0; j < N; ++j) {
				scanf("%d", &(S[i][j]));
			}
		}

		int each = N / 2;
		vector<bool> A(N, false);
		printf("#%d %d\n", t + 1, diff(A, 0, each));
	}

	return 0;
}