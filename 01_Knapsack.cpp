#include <bits/stdc++.h>
using namespace std;
int n;
const int N= 1000;
struct tuihang{
    int weight;
    int value;
};

tuihang A[N];
int m;
int dp[N][N];

input(){
    cin>> n>> m;
    for(int i =1; i<=n;i++){
        cin>>A[i].weight;
        cin>>A[i].value;
    }
    // for(int i =1; i<=n;i++){
    //     cout<<A[i].weight;
    //     cout<<A[i].value;
    // }
    
}

void solve(){
    for(int i =0; i<=m;i++) dp[0][i]=0;
    for(int i =0; i<=n;i++) dp[i][0]=0;
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=m; j++){
            
                dp[i][j]=dp[i-1][j]; // th khong lay do vat thu i
            
            if(A[i].weight <= j ){// th lay do vat thu i
                dp[i][j]=max(dp[i][j],dp[i-1][j-A[i].weight]+A[i].value);
            }
        }
    }
    cout<< dp[n][m];
}

int main(){
    input();
    solve();
    return 0;
}
