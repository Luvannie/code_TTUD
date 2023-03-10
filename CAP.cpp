#include <bits/stdc++.h>
using namespace std;
int n,m;
priority_queue<int> a,b;
int t;

void input(){
    cin >> t;
    cin>> n;
    for(int i =1; i<=n; i++){
        int x;
        cin  >> x;
        a.push(x);
    }

    cin >> m;
    for(int i =1; i<= m; i++){
        int x;
        cin>> x;
        b.push(x);
    }
    
}

void solve(){
    int cnt= 0;
    while(!a.empty()){
        int A=a.top();
        int B = b.top();
        if(A < B ){
            b.pop();
        }
        else if( A > B){
            a.pop();
        } else {
            cnt++;
            //cout << A ;
            a.pop();
            b.pop();
        }
    }
    cout<< cnt;
}
int main (){
    input();
    solve();
    return 0;
}