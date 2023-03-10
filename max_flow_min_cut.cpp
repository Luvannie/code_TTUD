#include <bits/stdc++.h>
using namespace std;
#define  N  1000000000
int n,m;
int s,t;
int parent[N];
int f[N][N];
int c[N][N];
vector<int> Adj[N];
int ans;
void input(){
    cin>>n>>m;
    cin>>s>>t;
    for(int i =1; i<=n;i++){
        for(int j = 1; j<=n;j++){
            c[i][j]=0;
        }
    }
    for(int k =1; k<=m; k++){
        int u,v, w;
        cin>> u>> v>> w;
        c[u][v]= w;
        Adj[w].push_back(v);
    }
}

bool findPathBFS(){
    queue<int> Q;
    memset(parent,0,sizeof(parent));
    Q.push(s);
    bool found = false;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i =0; i< Adj[u].size();i++){
            int v= Adj[u][i];
            if(parent[v]==0){
                bool ok =false;
                if(c[u][v] > 0){
                    if(f[u][v] < c[u][v]) ok =true;
                }else{
                    if(f[u][v] > 0) ok =true;
                }
                if(ok){
                    parent[v] = u;
                    Q.push(v);
                    if(v==t) return true;
                }
            }
        }
    }
    return false;
}


int argumentflow(){
    int delta = 1e9;
    int u = t;
    while(parent[u]!= 0){
        int pu = parent[u];
        if(c[pu][u] > 0){
            delta= min( delta, c[pu][u] - f[pu][u]);
        } else{
            delta= min(delta,f[pu][u]);
        }
        u=pu;
    }
    
    u = t;
    while(parent[u]!= 0){
        int pu = parent[u];
        if(c[pu][u] > 0){
            delta= min( delta, c[pu][u] - f[pu][u]);
        } else{
            delta= min(delta,f[pu][u]);
        }
        u=pu;
    }
    return delta;
}

void maxFlow(){
    for(int u =1; u <= n;u++){
        for(int i =0; i<Adj[u].size(); i++){
            int v = Adj[u][i];
            f[u][v] = 0;
        }
    }
    int ans = 0;
    while(true){
        bool ok = findPathBFS();
        if(!ok) break;
        int delta= argumentflow();
        ans += delta;
    }
}

int main(){
    input();
    maxFlow();
    return 0;
}
