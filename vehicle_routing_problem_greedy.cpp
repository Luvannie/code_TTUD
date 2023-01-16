#include <bits/stdc++.h>
using namespace std;
const int N= 100;
 const int INF = 1e9;
int n, K ,Q;// n la so luong kahch, k la so xe, q la tai trong tren moi xe
int d[N];// d[i] la khoi luong hang cua khach hang i
int c[N][N];// khoang cach giua cac khach hang va giua khach hang voi nha kho
vector <int> P[N];// hanh trinh cua cac xe
int F[N]; // do dai cua hanh trinh moi xe
int load[N]; // tai trong tren tuwng xe trong hanh trinh

void input(){
    scanf("%d%d%d",&n,&K,&Q);
    for(int i =1; i<=n; i++) scanf("%d",&d[i]);
    for(int i = 0; i<=n; i++){
        for(int j=0; j<=n;j++){
            scanf("%d",&c[i][j]);
        }
    }
    d[0] = 0; 
}

int selectTruck(){// chon xe dang co lo trinh la ngan nhat
    int minf= INF, select =-1;
    for(int k =1;k<=K;k++){
        if(minf > F[k]){
            minf = F[k];
            select= k;
        }
    }
    return select;
}

int selectClient(set<int>& C, int k){
    int select =-1; int minf=INF;
    int last = P[k][P[k].size() -1] ;// diem cuoi cung hien co tren hanh trinh cuar xe k   
    for(set<int>::iterator it=C.begin(); it!=C.end(); it++){//chon 1 ung cu vien
        int i=*it;        
        if(load[k] + d[i] <=Q){// neu ung cu vien do thoa man cac dieu kien, thi chon ung cu vien do
            if(minf > c[last][i]){
                minf=c[last][i];
                select =i;
            }
        }
    }
    return select;
}

void init(){
    for(int k =1; k<=K;k++){
        F[k] = 0; load[k]=0;
        P[k].clear() ;
        P[k].push_back(0);
    }
}

void printsolution(){
    int res=0;
    for(int k =1; k<=K; k++){
        F[k]+= c[P[k].size()-1][0];// di tu khach hang cuoi cung ve nha kho 0
        P[k].push_back(0);
    }
    for(int k =1; k<= K ; k++){
        
        cout<< "P["<<k<<"]: "<<endl;
        for(int i =0; i<=P[k].size();i++) {
            cout<< P[k][i]<<",";
        }
        cout<< "lenght:" << F[k]<<endl;
       res+= F[k];
    }
    cout << res;
}

void greedy1(){
    /*
    buoc 1: chon xe k la xe dang co lo trinh dai nhat
    buoc 2: chon khach hang i gan xe k nhat ma khong vi pham tai trong
    */
    init();
    cout<<"greedy1..."<<endl ;
    set<int> C;
    for(int i =1; i<=n; i++){
        C.insert(i);
    }
    //cout<< C.size();
    while(C.size()>0){
        int k = selectTruck();
        cout << "k: "<<k<<endl;
        int x = selectClient(C,k);
        cout<<"x:"<<x<<endl;
        if(x == -1){
            cout<< "cannot serve more client" << endl;
            break;
        }
        int last = P[k][P[k].size() - 1];
        load[k] += d[x];
        F[k] += c[last][x];
        P[k].push_back(x);
        C.erase(x);
    }
    printsolution();    
}

pair <int,int> selectTruckClient(set<int>& C){
    int sel_k = -1;
    int sel_i = -1;
    int minf=INF;
    for(int k =1; k<=K;k++){
        for(set<int>::iterator it= C.begin();it!=C.end();it++){
            int i = *it; // chon ra tung phan tu 1 trong tap hop cac ung cu vien C
            int last = P[k][P[k].size()-1];// last la hanh khach cuoi cung hien co tren chuyen xe k
            if(load[k] + d[i] > Q) continue;
            int maxL = F[k] + c[last][i];
            for(int j = 1; j<=K; j++){
                if(j!= K){
                    if(maxL < F[j]) maxL = F[j];
                }
            }
            if(minf > maxL){
                minf= maxL;
                sel_k = k;
                sel_i = i;
            }
            
        }
    }
    return make_pair<int,int>(sel_k,sel_i);
}

void greedy2(){
    init();
    set<int> C;
    for(int i =1; i<=n; i++) C.insert(i);
    while (C.size()>0)
    {
        pair<int, int> s= selectTruckClient(C);
        if(s.first == -1){
            cout<<"cannot serve more client "<< endl;
            break;
        }
        int k = s.first ;
        int x =s.second;
        int last = P[k][P[k].size() - 1];
        load[k] += d[x];
        F[k] += c[last][x];
        P[k].push_back(x);
        C.erase(x);
    }
    printsolution();

}


int main(){
    input();
    greedy2();
    //greedy1();
}