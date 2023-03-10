#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = 100010, inf = 0x3f3f3f3f;
int n, m, s, t, head[N], tot = 1, f[M], pre[N];
bool vis[N];
struct Edge {
    int to, nxt, w;
} e[M << 1];
void add(int x, int y, int z) {
    e[++tot].to = y, e[tot].nxt = head[x], e[tot].w = z;
    head[x] = tot;
}
bool bfs() {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s), vis[s] = 1, pre[s] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (!vis[y] && e[i].w) {
                vis[y] = 1, pre[y] = i;
                if (y == t) return 1;
                q.push(y);
            }
        }
    }
    return 0;
}
int dinic() {
    int ans = 0, flow;
    while (bfs()) {
        for (int i = head[t]; i; i = e[i].nxt) {
            int x = e[i].to;
            if (vis[x] && e[i ^ 1].w) {
                int y = e[i ^ 1].to;
                flow = inf, pre[y] = i ^ 1;
                for (int j = x; j != s; j = e[pre[j] ^ 1].to)
                    flow = min(flow, e[pre[j]].w);
                for (int j = x; j != s; j = e[pre[j] ^ 1].to)
                    e[pre[j]].w -= flow, e[pre[j] ^ 1].w += flow;
                ans += flow;
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int x, y, z;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z), add(y, x, 0);
    }
    printf("%d\n", dinic());
    return 0;
}
