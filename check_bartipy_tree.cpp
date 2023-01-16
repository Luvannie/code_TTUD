#include <bits/stdc++.h>
using namespace std;
#define N 100001
int n, m;

int d[N];
vector<int> A[N];
void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
bool BFS(int s) {
    queue<int> Q;
    int v;
    d[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int x = 0; x < A[v].size(); x++) {
            if (d[x] > -1) {
                if ((d[v] + d[x]) % 2 == 0) {
                    return false;
                }
            } else {
                Q.push(x);
                d[x] = d[v] + 1;
            }
        }
    }
    return true;
}

void solve() {
    int ans = 1;
    for (int v = 1; v <= n; v++) d[v] = -1;
    for (int v = 1; v <= n; v++) {
        if (d[v] == -1) {
            bool ok = BFS(v);
            if (!ok) {
                ans = 0;
                break;
            }
        }
    }
    cout << ans;
}

int main() {
    input();
    solve();
}
