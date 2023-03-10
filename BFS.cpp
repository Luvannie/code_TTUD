#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
vector<int> A[N];
queue<int> Q;
vector<int> ans;
bool visited[N];
int x,y;
void input(){
    cin>> n >> m;
    for(int i =1; i<= m;i++){
        cin >> x >> y;
        A[x].push_back(y);
        //A[y].push_back(x);
        visited[x] = false;
        visited[y] = false;
    }
}

void BFS_node(int u) {
    int v;
    Q.push(u);
    visited[u] = true;
    while(!Q.empty()){
        v= Q.front();
        ans.push_back(v);
        Q.pop();
        visited[v] = true;
        for(int i =0; i< A[v].size(); i++){
            int z = A[v][i];
            if(visited[z] == false){
                Q.push(z);
                visited[z] = true;
            }
        }
    }
}

void BFS(){
    for(int i =1; i<= n; i++){
        if(visited[i] == false){
            BFS_node(i);
        }
    }
    for(int i =0; i< ans.size(); i++){
        int c = ans[i];
        cout<< c << " ";
    }
    cout<<endl;
    
}

int main(){
    input();
    BFS();
    return 0;
}