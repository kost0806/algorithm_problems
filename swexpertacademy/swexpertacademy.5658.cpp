/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
* Kostrian(Minyeong Kim, kost0806)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N >> K;
        char *tmp_arr = new char[N];
        short *arr = new short[N];
        vector<long> num_list;
        for (int i = 0; i < N; ++i)
            cin >> tmp_arr[i];

        for (int i = 0; i < N; ++i) {
            if (tmp_arr[i] >= 'A' && tmp_arr[i] <= 'F')
                arr[i] = tmp_arr[i] - 'A' + 10;
            else
                arr[i] = tmp_arr[i] - '0';
        }

        int per_edge = N / 4;
        for (int offset = 0; offset < per_edge; ++offset) {
            for (int i = 0; i < 4; ++i) {
                long num = 0;
                long _16 = 1;
                for (int j = per_edge - 1; j >= 0; --j, _16 *= 16) {
                    num += arr[(offset + per_edge * i + j) % N] * _16;
                }
                bool flag = false;
                for (vector<long>::iterator iter = num_list.begin(); iter != num_list.end(); ++iter) {
                    if (*iter == num) {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    num_list.push_back(num);
            }
        }

        sort(num_list.begin(), num_list.end(), greater<int>());

        cout << "#" << t << " " << num_list[K - 1] << "\n";
    }

    return 0;
}