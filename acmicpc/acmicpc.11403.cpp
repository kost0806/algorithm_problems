// https://www.acmicpc.net/problem/11403

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N;
bool map[100][100];
vector<int> nodes[100];

void explore() {
    for (int n = 0; n < N; ++n) {
        queue<int> q;
        q.push(n);

        while (!q.empty()) {
            vector<int> &current = nodes[q.front()];
            q.pop();

            for (int j = 0; j < current.size(); ++j) {
                if (map[n][current[j]])
                    continue;
                q.push(current[j]);
                map[n][current[j]] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int connected;
            scanf("%d", &connected);

            if (connected == 1) {
                nodes[i].push_back(j);
            }
        }
    }

    memset(map, 0, sizeof(map));

    explore();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d", map[i][j]);
            if (j < N - 1)
                printf(" ");
        }
        printf("\n");
    }
}
