#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int dp[N];
int n;
int a[N];
int S;
void input(){
    cin>> n >> S;
    for(int i =1; i<=n; i++) cin>> a[i];
}

void solve(){
    dp[0]=true;
    for(int i =1; i<=n;i++){
        for(int j = S;j>=a[i];j-- ){
            if(dp[j-a[i]]==true) dp[j]==true;
        }
    }
    if(dp[S]==true) cout<< 1<< endl;
    else cout<< 0 << endl;
}

int main()
{
    /* code */
    input();
    solve();
    return 0;
}
