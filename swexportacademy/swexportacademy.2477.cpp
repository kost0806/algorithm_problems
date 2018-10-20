/*
* https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy
* Kostrian(Minyeong Kim, kost0806)
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

enum class C_STATE {
    NOT_ARRIVED, A_WAIT, A_SERVICE, B_WAIT, B_SERVICE, DONE
};

typedef struct {
    short num;
    short arrival_time;
    short a_num;
    short b_num;
    C_STATE state;
} customer;

typedef struct {
    short required;
    short remained;
    short service;
} worker;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    int N, M, K, A, B;
    worker *a, *b;
    customer *k;

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N >> M >> K >> A >> B;
        a = new worker[N];
        b = new worker[M];
        k = new customer[K];
        queue<int> a_queue;
        queue<int> b_queue;

        for (int i = 0; i < N; ++i) {
            cin >> a[i].required;
            a[i].remained = 0;
            a[i].service = -1;
        }

        for (int i = 0; i < M; ++i) {
            cin >> b[i].required;
            b[i].remained = 0;
            b[i].service = -1;
        }

        for (int i = 0; i < K; ++i) {
            cin >> k[i].arrival_time;
            k[i].num = i;
            k[i].a_num = -1;
            k[i].b_num = -1;
            k[i].state = C_STATE::NOT_ARRIVED;
        }

        int time = k[0].arrival_time, last_arrived = -1, done_count = 0;
        while (!(done_count == K)) {
            done_count = 0;
            for (int i = last_arrived + 1; i < K; ++i) {
                if (k[i].arrival_time > time) {
                    break;
                }
                else if (k[i].arrival_time == time) {
                    k[i].state = C_STATE::A_WAIT;
                    last_arrived = i;
                    a_queue.push(i);
                }
            }

            for (int i = 0; !a_queue.empty() && i < N; ++i) {
                if (a[i].service == -1) {
                    a[i].service = a_queue.front();
                    a[i].remained = a[i].required;
                    k[a_queue.front()].state = C_STATE::A_SERVICE;
                    k[a_queue.front()].a_num = i;
                    a_queue.pop();
                }
            }

            for (int i = 0; i < N; ++i) {
                if (a[i].service != -1 && a[i].remained > 0) {
                    --a[i].remained;
                    if (a[i].remained == 0) {
                        k[a[i].service].state = C_STATE::B_WAIT;
                        b_queue.push(a[i].service);
                        a[i].service = -1;
                    }
                }
            }


            for (int i = 0; !b_queue.empty() && i < M; ++i) {
                if (b[i].service == -1) {
                    b[i].service = b_queue.front();
                    b[i].remained = b[i].required;
                    k[b[i].service].state = C_STATE::B_SERVICE;
                    k[b[i].service].b_num = i;
                    b_queue.pop();
                }
            }

            for (int i = 0; i < M; ++i) {
                if (b[i].service != -1 && b[i].remained > 0) {
                    --b[i].remained;
                    if (b[i].remained == 0) {
                        k[b[i].service].state = C_STATE::DONE;
                        b[i].service = -1;
                    }
                }
            }

            for (int i = 0; i < K; ++i) {
                if (k[i].state == C_STATE::B_SERVICE || k[i].state == C_STATE::DONE)
                    ++done_count;
            }

            ++time;
        }

        int ret = 0;
        for (int i = 0; i < K; ++i) {
            if (k[i].a_num == A - 1 && k[i].b_num == B - 1) {
                ret += i + 1;
            }
        }

        cout << "#" << t << " " << (ret == 0 ? -1 : ret) << "\n";

        free(k); free(b); free(a);
    }

    return 0;
}