#include <bits/stdc++.h>
using namespace std;

const int N=5100;
const int M=10010;
const int INF=1e9;

int n,m;
int c[N],d[N];
int head[N];
int dist[N];
bool vis[N];
int tot=0;

struct node {
  int v,w,next;
}e[M<<1];

void add(int u,int v,int w) {
  e[++tot].v=v;
  e[tot].w=w;
  e[tot].next=head[u];
  head[u]=tot;
}

void dijkstra() {
  memset(dist,0x3f,sizeof(dist));
  memset(vis,0,sizeof(vis));
  dist[1]=0;
  priority_queue<pair<int,int>> q;
  q.push({0,1});
  while(!q.empty()) {
    int u=q.top().second;
    q.pop();
    if(vis[u]) continue;
    vis[u]=1;
    for(int i=head[u];i;i=e[i].next) {
      int v=e[i].v;
      int w=e[i].w;
      if(dist[v]>dist[u]+w) {
        dist[v]=dist[u]+w;
        if(!vis[v]) q.push({-dist[v],v});
      }
    }
  }
}

int main() {
  cin>>n>>m;
  for(int i=1;i<=n;i++) {
    cin>>c[i]>>d[i];
  }
  int u,v;
  for(int i=1;i<=m;i++) {
    cin>>u>>v;
    add(u,v,0);
    add(v,u,0);
  }
  for(int i=1;i<=n;i++) {
    for(int j=i+1;j<=n;j++) {
      int w=min(d[i],d[j])*(c[i]+c[j]);
      add(i,j,w);
      add(j,i,w);
    }
  }
  dijkstra();
  cout<<dist[n]<<endl;
  return 0;
}
