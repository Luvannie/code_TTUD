#include <bits/stdc++.h>
using namespace std;
const int N= 1e5;
int n, m;
vector <int> A[N];
vector <int> ans;
bool visited[N] ;
int x, y;

void input(){
    cin>> n >> m;
    for(int i =1; i<= m;i++){
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
        visited[x] = false;
        visited[y] = false;
    }
}

void DFS(int u){
    ans.push_back(u);
    visited[u]= true;
    for(int v=0; v<A[u].size(); v++){
        int c = A[u][v];
        if(visited[c]==false){
            DFS(c);
        }
    }
}

void DFS(){
    for(int v =1; v<=n; v++){
        if(visited[v]== false) DFS(v);
    }
    for(int i =0; i< ans.size(); i++){
        int c = ans[i];
        cout<< c << " ";
    }
    cout<<endl;
}

int main(){
    input();
    DFS();
    return 0;
}