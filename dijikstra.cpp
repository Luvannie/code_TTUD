#include <bits/stdc++.h>
using namespace std;
int n,m ;
#define inf  1e9
const int N = 1000001;

#define pii pair<int,int>
struct Arc{// tao ra cap, trong do phan tu dau tien la dinh ke, phan tu thu 2 la trong so
    int v;
    int w;
    Arc(int _v,int _w){
        v= _v;
        w=_w;
    }
};

vector<Arc> A[N];//danh sach dinh ke va trong so luu trong mang vector
int p[N];
int s,t;
void input(){
    int u , v, w;
    scanf("%d%d",&n,&m);
    for(int i =1; i<=m; i++){
        scanf("%d%d%d",&u,&v,&w);
        A[u].push_back(Arc(v,w));
        A[v].push_back(Arc(u,w));
    }
    scanf("%d%d",&s,&t);
}

void dijikstra_priorityqueue(int s){
    vector<long long> d(n+1,inf); // mang luu khoang cach va duong di
    d[s] = 0; // khoang cach tu 1 dinh den chinh no thi bang 0
    priority_queue<pii,vector<pii>,greater<pii> > Q; //hang doi uu tien {khoang cach, dinh}, sap sep theo do dai cua 
    Q.push({0,s}); // day dinh s vao danh sach uu tien, khoang cach cua dinh nguon(dang la s) toi s la bang 0
    while(!Q.empty()){
        // chon ra dinh co khoang cach tu s toi no la nho nhat
        pii top = Q.top();
        Q.pop();
        int u = top.second; // dinh tiep theo de duyet
        int kc = top.first; // khoang cach ngan nhat
        if(kc > d[u]) continue;
        // cap nhat lai khoang cach tu dinh s cho toi moi dinh lien ke voi u
        for(vector<Arc>::iterator it = A[u].begin(); it!= A[u].end(); it++ ){
            Arc i = *it;
           int v= i.v; // dinh ke tiep theo cua u
           int w =i.w; // trong so cua canh(u,v)
            if(d[v] > d[u] + w){ // neu khoang cach tu s toi v, lon hon khoang cach tu s di qua u roi toi v
                d[v] = d[u] + w;
                Q.push({d[v],v}); // dua vao danh sach cac ung cu vien tiep theo sau dinh u
            }
        }
    }
   cout<< d[t] << endl;
}
int main(){
    input();
    dijikstra_priorityqueue(s);
}
