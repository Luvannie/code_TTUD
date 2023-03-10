#include <bits/stdc++.h>
using namespace std;

int n ;
int a[10000];
int L[10000];// L[i] la do dai cua day con tang dai nhat tinh toi chi so i

void input(){
    cin>>n;
    for(int i =0; i< n; i++){
        cin >> a[i];
        L[i]=1;
    }
}

void solve(){
    for(int i =1; i<n; i++){
        for(int j =0 ;j<i;j++){
            if(a[i]>a[j]){
                L[i]=max(L[i],L[j]+1);
            }
        }
    }
    int res = 0;
    for(int i =0;i<n;i++){
        res=max(res,L[i]);
    }
    cout<<res;
}

int main(){
    input();
    solve();
    return 0;
}