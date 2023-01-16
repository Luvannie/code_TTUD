#include <bits/stdc++.h>
using namespace std;
#define N 100001
int n;
struct edge {
    int node;
    int w;
    edge(int _node, int _w) {
        node = _node;
        w = _w;
    }
};
int d[N];
vector<edge> A[N];

void input() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u].push_back(edge(v, w));
        A[v].push_back(edge(u, w));
    }
}

int BFS(int u) {
    queue<int> Q;
    for (int v = 1; v <= n; v++) {
        d[v] = -1;
    }
    Q.push(u);
    d[u] = 0;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < A[v].size(); i++) {
            edge e = A[v][i];
            int x = e.node;
            int w = e.w;
            if (d[x] == -1) {
                Q.push(x);
                d[x] = d[v] + w;
            }
        }
    }
    int maxD = 0;
    int sel_v = -1;
    for (int v = 1; v <= n; v++) {
        if (d[v] > maxD) {
            maxD = d[v];
            sel_v = v;
        }
    }
    return sel_v;
}

void solve() {
    int s = 1;
    int x = BFS(s);
    // cout << "pha 1 "
    int i = BFS(x);
    int answer = i;
    cout << answer << endl;
}

int main() {
    input();
    solve();
}