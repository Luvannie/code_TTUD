#include <bits/stdc++.h>
using namespace std;
const int Q= 1e6;
int N,M;
vector<int> A[Q];
bool CriticalNode[Q];
void input(){
    cin>> N>>M;
    int x, y;
    for(int i=1; i<=M;i++){
        cin>> x>> y;
        A[x].push_back(y);
        A[y].push_back(x);
        // CriticalNode[x]=false;
        // CriticalNode[y]=false;
    }
}

int Low[Q], Num[Q]; // Num[i] la so thu tu cua dinh i khi dinh huong, Low[i] la so topo nho nhat cua dinh i
// Low[i] la so thu tu cua dinh nho nhat ma trong do thi lien thong co goc la i
 int Time,CriticalEdge;

void visit(int u , int p) {
    int numchild = 0; 
    Low[u]=Num[u] = ++Time;
    for(int i =0; i<A[u].size(); i++){
        int v= A[u][i];
        if(v!=p){
            if(Num[v]){
                Low[u]=min(Low[u],Num[v]);
            }
            else{
                visit(v,u);
                ++numchild;
                Low[u]= min(Low[u],Low[v]);
                if(Low[v]> Num[u]){
                    ++CriticalEdge;
                }
                if(u==p){
                    if(numchild >= 2) CriticalNode[u]=true;
                }
                else{
                    if(Low[v] >= Num[u]) CriticalNode[u]=true;
                }
            }
        }
    }
}

void proc(){
    for(int i =1; i<=N;i++){
        if(!Num[i]) visit(i,1);
    }
    int count = 0; 
    for(int i =1; i<=N; i++){
        if(CriticalNode[i]) count++;
    }
    cout<< count<<" "<<CriticalEdge<< endl;


}
int main(){
    input();
    proc();
    return 0;
}