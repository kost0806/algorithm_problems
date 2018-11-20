// https://www.acmicpc.net/problem/1260

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> node[1001];
bool visit[1001];

void dfs();
void bfs();

int main() {
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        node[a].push_back(b);
        node[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        sort(node[i].begin(), node[i].end(), greater<int>());
    }
    dfs();

    for (int i = 1; i <= N; ++i) {
        sort(node[i].begin(), node[i].end());
    }
    bfs();
}

void bfs() {
    queue<int> q;

    memset(visit, 0, sizeof(visit));

    q.push(V);
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (visit[current])
            continue;
        visit[current] = true;
        printf("%d ", current);

        for (int i = 0; i < node[current].size(); ++i) {
            if (visit[node[current][i]])
                continue;
            q.push(node[current][i]);
        }
    }
    printf("\n");
}

void dfs() {
    deque<int> q;

    memset(visit, 0, sizeof(visit));

    q.push_back(V);
    while (!q.empty()) {
        int current = q.back();
        q.pop_back();

        if (visit[current])
            continue;
        visit[current] = true;
        printf("%d ", current);

        for (int i = 0; i < node[current].size(); ++i) {
            if (visit[node[current][i]])
                continue;
            q.push_back(node[current][i]);
        }
    }
    printf("\n");
}