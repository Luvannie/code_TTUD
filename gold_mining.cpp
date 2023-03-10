#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n , L1, L2; // n la so luong mo vang, L1, L2 la gioi han khoang cach
int a[N];// luu luong vang co trong tung mo, chi so chay tu 1
int F[N];// F[i] la so luong vang lon nhat neu chon tu nha kho 1 toi i-1 va nha kho thu i duoc chon
int res =0;
typedef pair<int,int> ii;
vector<ii> b;
priority_queue<ii> hd;
void input() {
    scanf("%d%d%d",&n,&L1,&L2);
    for(int i =1; i<=n; i++){
        scanf("%d",&a[i]);
        F[i]=a[i];// khoi tao
    }
}

void solveBottomUp(){
    for(int i = 1; i<= n; i++){
        
        if(i-L1 > 0){
            cout<<"a"<<endl;
        cout<<F[i-L1]<<" "<<i-L1<<endl;
             hd.push(ii(F[i-L1],i-L1));// dua vao hang doi uu tien , o day laf dua cac cap F[i],i vao hang doi va sap sep theo F[i]
        }
        while(!hd.empty()){
            if(hd.top().second < i -L2){
                //vi ham F[i] luon lon hon F[j] voi moi j< i( ham F la tinh tong ) nen theo tinh chat cua pririty_queue thi
                //phan tu dung dau co chi so gan voi i nhat
                cout<<"b"<<endl;
                cout<<hd.top().first<<" "<< hd.top().second<<i-L2<<endl;
                hd.pop();} //
            
            else break;
        }
        
        if(!hd.empty()) {
          F[i] = hd.top().first + a[i];  
          cout<<"c"<<endl;
          cout<<hd.top().second<<" "<<i<<endl;
        } 
   ;
        res = max(F[i],res);
       
    }
    cout<< res<<endl;
}

int main(){
    input();
    solveBottomUp();
}