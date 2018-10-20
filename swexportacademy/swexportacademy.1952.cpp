/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq
* Kostrian(Minyeong Kim, kost0806)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;


int T;
int p[4];
short times[12];
int cnt = 0;

int evaluate(int payment, int idx) {
	int ret = 999999;

	if (idx >= 12)
		return payment;

	if (idx < 10)
		ret = min(ret, evaluate(payment + p[2], idx + 3));
	if (idx < 12)
		ret = min(ret, evaluate(payment + p[1], idx + 1));
	if (idx < 12)
		ret = min(ret, evaluate(payment + (times[idx] * p[0]), idx + 1));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(times, 0, sizeof(times));
		for (int i = 0; i < 4; ++i) {
			cin >> p[i];
		}
		for (int m = 0; m < 12; ++m)
			cin >> times[m];

		int ret = min(p[3], evaluate(0, 0));
		printf("#%d %d\n", t + 1, ret);
	}
	return 0;
}