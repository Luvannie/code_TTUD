#include <bits/stdc++.h>
using namespace std;
#define inf -1e9 
#define N 10000000
int n;
int a[N]={0};
int S[N]={0};
void input(){
    scanf("%d",&n);
    for(int i = 1; i<=n ; i++) scanf("%d",&a[i]);
}

void solveBottomUp(){
    S[1]= a[1];
    int res= a[1];
    for(int i =2; i<=n;i++){
        if(S[i-1] >0) S[i]=S[i-1] + a[i];
        else S[i] = a[i];
        res = max(res,S[i]);
    }
    cout<< res;
}

int F(int i){
    if(i==1){
        S[1] = a[1];
        return S[1];

    }
    if(S[i]==inf){
        int b = F(i-1);
        if(b> 0) S[i]= b+ a[i];
        else S[i] = a[i];
    }
    return S[i];
}

void solveTopDown(){
    int res = inf;
    for( int i =1; i<= n; i++) S[i] = inf;
    for ( int i =1; i<=n;i++){
        int tmp= F(i);
        res= max(res,tmp);
    }
    cout<< res<<endl;
}

int main(){
    input();
    solveBottomUp();
    //solveTopDown();
    return 0;
}
