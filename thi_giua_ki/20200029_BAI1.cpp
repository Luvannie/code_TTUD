#include <bits/stdc++.h>
using namespace std;
int n,k,m;
int cnt= 0;
const int N=1e5+1;
int a[N];
void input(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i =1; i<=n;i++){
        scanf("%d",&a[i]);
    }
}

void solve(){
    for(int i =1; i<=n - k+1;i++){
        int sum =0;
        for(int j = 0; j<k;j++){
            sum+= a[i+j];
        }
        if(sum==m){
            cnt++;
        }
    }
}
int main(){
    input();
    solve();
    printf("%d",cnt);
    return 0;
}