#include <bits/stdc++.h>
using namespace std;
const int M = 1001;
int N,T,D;
int a[N], t[N];
int count_time;
int count_distant;
int x[N];
void input(){
    scanf("%d%d%d",&N,&T,&D);
    for(int i =1 ; i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i =1 ; i<=n;i++){
        scanf("%d",&t[i]);
    }
}

bool check(int v ,int k){// kiem tra xem dia diem thu k co the la dia diem v hay khong
    for(int i =1; i<k;i++){
        if(i==v) return false;
    }
    if(count_ti)


}

void Try(int k){
    for(int v =1; v<= n; v++){
        if(check(v,k)){
            x[k] = v;
            count_time += t[v];
            
        }
    }
}

int main(){
    input();
}