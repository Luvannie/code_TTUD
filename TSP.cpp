#include <bits/stdc++.h>
using namespace std;
const int maxx = 100;
int n, c[maxx][maxx];
int cmin = INT_MAX; // so thanh pho, ma tran chi phi
int best = INT_MAX; // chi phi di lai nho nhat giau hai thanh pho
int curr;//tong hi phi toi thoi diem hien tai
bool mark[maxx];// danh dau thanh pho da di
int x[maxx]; //luu tru cac thanh pho da di

void input(){
    cin>> n;
    for(int i =1; i<= n;++i){
        for(int j=1; j<=n;++j){
            scanf("%d",&c[i][j]);
            if(c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
        mark[i]= false;
    }
}

void Try(int k){
    for(int i =2; i<=n ; i++){
        if(!mark[i]){
            x[k]= i;
            mark[i] = true;
            curr += c[x[k-1]][x[k]];
            if(k==n) best = min(best,curr+ c[i][1]);
            else if(curr+ cmin*(n-k+1)<best) Try(k+1);
            mark[i]=false;
            curr -= c[x[k-1]][x[k]];
        }
    }
}

int main(){
    input();
    x[1]=1;
    Try(2);
    cout<< best;
    return 0;
}
