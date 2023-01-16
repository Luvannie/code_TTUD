
#include <bits/stdc++.h>
using namespace std;
#define N 100001
int n, m; // n is number of node, m is number of edge
struct edge{
    int u,v;
    int w;
    edge(int _u,int _v,int _w){
        u= _u;
        v= _v;
        w= _w;
    }
};
int p[N], r[N]; // p is parent array, r is rank array
vector<edge> E;
vector<edge> TE;
int find(int x){
    if(p[x]== x) return x;
    p[x]=find(p[x]);
    return p[x];
}

bool compare(edge e1, edge e2){
    return e1.w <= e2.w;
}

void print(){
    for(int i =0; i< E.size();i++){
        cout<< E[i].u <<","<<E[i].v << "," << E[i].w << endl;
    }
}

void makeset(int x){
    p[x]= x;
    r[x]= 0;
}
void unity(int x, int y){
    if(r[x]> r[y]) p[y] = x;
    else{
        p[x]= y;
        if(r[x]==r[y]){
            r[y]=r[y]+1;
        }
    }
}
void input(){
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i =1; i<=m; i++){
        scanf("%d%d%d", &u, &v, &w);
        E.push_back(edge(u,v, w));        
    }
}

void solve(){
    sort(E.begin(),E.end(),compare);
    //print();
    for(int v= 1; v<= n; v++) makeset(v);
    long long ans = 0;
    for( int i = 0 ; i<E.size(); i++){
        int u = E[i].u, v=E[i].v, w=E[i].w;
        int ru = find(u);
        int rv= find(v);
        
        if(ru!= rv){
            unity(ru,rv);
            /*if(r[ru]> r[rv]) p[rv] = ru;
    		else{
        		p[ru]= rv;
        		if(r[ru]=r[rv]){
            		r[rv]=r[rv]+1;
        			}
    			}*/
            ans += w;
            TE.push_back(E[i]);
            
            if(TE.size()== n-1) break;
        }
    }
    cout<< ans<< endl;
    
}
int main(){
    input();
    solve();
    return 0;
}
