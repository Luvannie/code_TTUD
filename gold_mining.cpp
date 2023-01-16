#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n , L1, L2; // n la so luong mo vang, L1, L2 la gioi han khoang cach
int a[N];// luu luong ang co trong tung mo, chi so chay tu 1
int F[N];
int res =0;
typedef pair<int,int> ii;
vector<ii> b;
priority_queue<ii> hd;
void input() {
    scanf("%d%d%d",&n,&L1,&L2);
    for(int i =1; i<=n; i++){
        scanf("%d",&a[i]);
        F[i]=a[i];
    }
}

void solveBottomUp(){
    for(int i = 1; i<= n; i++){
        
        if(i-L1 > 0) hd.push(ii(F[i-L1],i-L1));// dua vao hang doi uu tien 
        
        while(!hd.empty()){
            if(hd.top().second < i -L2) hd.pop();//
            else break;
        }
        
        if(!hd.empty())  F[i] = hd.top().first + a[i];
   ;
        res = max(F[i],res);
       
    }
    cout<< res<<endl;
}

int main(){
    input();
    solveBottomUp();
}