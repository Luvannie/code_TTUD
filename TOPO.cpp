#include <bits/stdc++.h>
using namespace std;
const int N =1e5;
int n,m;
int d[N]; // d[v] laf so ban bac vao cua dinh v
queue<int> Q;
int x, y;
vector<int> A[N]; // A[v] la danh sach cac dinh co canh co huong voi dinh v
vector<int> L;

void input(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        A[x].push_back(y);
        d[y]++;
    }
}

void TOPO(){
    for(int u =1; u<=n;u++){
        if(d[u]==0) {
            Q.push(u);
            }
    }
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        cout<< v<<endl;
        L.push_back(v);
        for(int i = 0 ;i<A[v].size();i++){
            int c= A[v][i];
            d[c]= d[c]-1;
            if(d[c]==0) Q.push(c);
        }
    }
    
    for(int i = 0; i< L.size(); i++) {
        cout<< L[i] << " ";
    }    
}
int main(){
    input();
    TOPO();
    return 0;
}