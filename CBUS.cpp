#include <bits/stdc++.h>
using namespace std;
const int N= 25;
int n , q;// n customer, q seat 
int f, f_best =1e9; // f la do dai bo phan lo trinh, f_best ghi nhanh lo trinh ngan nhat
int load;// ghi nhan so khach dang tren xe
bool visited[N];// danh dau xem xe da qua tram nay chua
int x[N]; // ghi nhan lai lo trinh
int c[N][N];
int dmin =1e9;
void input(){
    scanf("%d %d",&n,&q);
    for(int i = 0; i<=2*n ;i++){
        for(int j =0; j<=2*n; j++){
            scanf("%d",&c[i][j]);
            if(i!= j && c[i][j] < dmin) dmin = c[i][j];            
        }
        //visited[i]= false;
    }
}

bool check(int v, int k){
    if(visited[v]) return false;
    if(v<=n){ // v la diem don
        if(load>= q){// qua suc chua
            return false;
        }
    }else{// v la diem tra
        if(!visited[v-n]){// chua don hanh khach ma da toi diem tra
            return false;
        }
    }
    return true;
}

void updatebest(){
    if(f + c[x[2*n]][x[0]] < f_best){
        f_best = f + c[x[2*n]][x[0]];
    }
}

void Try(int k){
    for(int v = 1; v<=2*n;v++){
        if(check(v,k)){
            x[k]=v;    
            f+=c[x[k-1]][x[k]];
            if(v<=n) load +=1;// den diem don thi don khach
            else load -= 1; // den diem tra thi tra khach
            visited[v]= true;
            if(k==2*n){
                updatebest();    
            }else{
                if(f + dmin*(2*n+1-k) < f_best) Try(k+1);
            }
            // khoi phuc trang thai
            visited[v]= false;
            f-=c[x[k-1]][x[k]];
            if(v<=n) load -=1;
            else load += 1; 
        }
    }
}

int main(){
    input();
    for(int v =1; v <= 2*n; v++) visited[v]= false;
    f= 0; load = 0;
    x[0]= 0;

    Try(1);
    cout<<f_best;
    /*for(int i = 0 ; i<= 2*n; i++){
        for(int j = 0 ; j<= 2*n; j++){
            cout<<c[i][j] << " ";
        }
        cout << endl;
    }*/
}