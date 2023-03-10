#include <bits/stdc++.h>
using namespace std;
const int N = 3e6;
const int inf = 1e9;
int n, L[N+1], R[N+1];// L[i] la do dai doan lon nhat ve phia ben trai cua i, R[i] la do dai lon nhat ve phia ven phai cua i

inline void Read(int &n){
    char c; n=0;
    do{
         c = getchar();

    } while (!isdigit(c));
    do{
         n = n*10 + c -48;
         c = getchar();
    } while (isdigit(c));    
}

void solve(){
    for(int i =0; i<= N+1; ++i) L[i] = R[i]= -inf;
    Read(n);
    while(n--){
        int a, b;
        Read(a);
        Read(b);
        R[a] = max(R[a],b-a);
        L[b] = max(L[b],b-a); 
    }
    for(int i =1; i<=N; ++i) L[i] = max(L[i-1], L[i]);
    for(int i =N; i>=1; --i) R[i] = max(R[i], R[i-1]);
    int ans =-inf;
    for(int i =1; i<=N-1;++i) ans = max(ans,L[i] + R[i+1]);
    if(ans == -inf) ans =1;
    cout << ans;
 }

int main(){
    solve();
    return 0;
}