#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,m;
vector<pair<int,int> > bridge;
vector<int> A[N];
bool visited[N];
int num[N];
int low[N];
int t;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i =1; i<= m; i++){
        int x, y;
        cin>>x>>y;
        A[x].push_back(y);
        A[y].push_back(x);  
    }
}

void DFS(int s, int ps){
    //DFS from s with ps is the parent of s in the  DFS tree
    t++;
    num[s] = t;
    low[s] = num[s];
    visited[s] = true;
    for(int i = 0; i< A[s].size();i++){
        int v= A[s][i];
        if(v == ps) continue;
        if(visited[v] == true){
            low[s] =   min(low[s], low[v]);
        }else{
            DFS(v,s);
            low[s] = min(low[s],low[v]);
            if(low[v] > num[s]){
                //discover a brigde
                bridge.push_back(make_pair(s,v));
            }
        }

    }
}

void init(){
    for(int i=1; i<=n; i++) visited[i]=false;
}

void solve(){
    init();
    t =0;
    for(int s= 1; s<=n; s++){
        if(!visited[s]){
            DFS(s,-1);
        }
    }
    cout<<"bridges: "<<endl;
    for(int i =0; i< bridge.size(); i++){
        cout << "("<<bridge[i].first << ", "<< bridge[i].second<<")";
    }
}
int main(){
    input();
    solve();
    return 0;
}