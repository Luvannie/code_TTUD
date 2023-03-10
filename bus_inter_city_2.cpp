// #include<bits/stdc++.h>
// using namespace std;

// const int N=5100;
// const int M=10010;
// const int INF=1e9;

// int n,m; // n la so thanh pho, m la so luong duong di giua cac thanh pho, 1 thanh pho chi co 1 tuyen buyt
// int c[N],d[N]; // c[i] la gia ve moi khi len xe o thanh pho i, va d[i] la so thanh pho toi da co the di tu tuyen buyt i
// int head[N];
// int dist[N];
// bool vis[N];
// int tot=0;

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int INF = 1e9 + 7;

int n, m, cur, dist[MAXN], C[MAXN], D[MAXN];
bool vis[MAXN];

vector<int> adj[MAXN], cost[MAXN];

void Dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, source}); // {distance, vertex}

    while (!pq.empty())
    {
        int prev = pq.top().second;
        pq.pop();

        if (vis[prev])
            continue;
        vis[prev] = true;

        for (int i = 0; i < adj[prev].size(); i++)
        {
            int next = adj[prev][i], weight = cost[prev][i], en = min(cur, D[prev]);
            // di chuyển đến được bao nhiêu thành phố duỗi theo giá vé tối thiểu 
            int new_dist = dist[prev] + weight * C[prev]; 

            if (en <= 0 || new_dist >= INF)
                continue; // không thể di chuyển hoặc quá mức chi phí

            if (dist[next] > new_dist) // nếu tìm được đường đi ngắn hơn
            {
                dist[next] = new_dist;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> C[i] >> D[i];

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u); // đường kết nối hai thành phố là hai chiều
        cost[u].push_back(1), cost[v].push_back(1);
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[1] = 0;

    for (cur = 1; cur <= n; cur++)
    {
        memset(vis, false, sizeof vis);
        Dijkstra(1);
    }

    cout << dist[n];

    return 0;
}
