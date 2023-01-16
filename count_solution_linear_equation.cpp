#include <bits/stdc++.h>
using namespace std;
int n, m, f= 0;
#define MAX  20 
int t[MAX]={0}, a[MAX]={0};
int COUNT = 0;

int x[MAX];
void solution(){
    if(f==m){
        COUNT++;
    }
}

void TRY(int k){
    int v;
    for( v = 1; v<=(m-f-(t[n]-t[k]))/a[k];v++){
        x[k]=v;
        f+= a[k]*x[k];
        if(k==n){
            solution();
        }
        else{
            TRY(k+1);
        }
        f-= a[k]*x[k];
    }
}

int main() {
    cin>> n >> m;
    for(int i = 1 ; i<n+1;i++ ){
        cin >> a[i];
        t[i] = t[i-1] + a[i];
    }
    TRY(1);
    cout<<COUNT;
}
