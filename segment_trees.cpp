#include <bits/stdc++.h>
using namespace std; 
const int N =1e5+ 1;
int n, m;
int a[N];
int maxval[N<<2];

int getMaxFromNode(int id, int left, int right,int x, int y){
    //retrieve the max value  of the interval[x,y] starting from node(id, [left,right])
    if( x> right|| y<left) return 0;
    if(x <= left && y >= right) return maxval[id];
    int m = (left+ right)/2 ;
    int leftID = id<<1;
    int rightID = id<<1 | 1;
    int maxleft= getMaxFromNode(leftID,left,m,x,y);
    int maxright = getMaxFromNode(rightID,m+1,right,x,y);
    return max(maxleft,maxright); 
}

int getmax(int x, int y){
    return getMaxFromNode(1,1,n,x,y);
}

void updateFromNode(int id,int left,int right,int index, int value){
    if(left > right) return ;
    if(left > index || right< index) return;
    if(left==right){
        maxval[id]=value;
        return;
    }
    int leftId = id<<1;
    int rightID = id <<1 | 1;
    int m =(left+ right)/2;
    updateFromNode(leftId,left,m,index,value);
    updateFromNode(rightID,m+1,right,index,value);
    maxval[id]=max(maxval[leftId],maxval[rightID]);
}

void update(int index,int value){
    updateFromNode(1,1,n,index,value);
}

void solve(){
    memset(maxval,0,sizeof maxval);// sao chep ki tu
    cin>> n;
    for(int i =1; i<= n; i++) cin>>a[i];
    for(int i =1; i <=n; i++) update(i,a[i]);
    cin>> m;
    string type;
    for(int i =1; i<= m; i++){
        cin>> type;
        if(type =="update"){
            int i, v;
            cin>> i>> v;
            a[i]=v;
            update(i,v);
        }
        if(type =="get-max"){
            int c,d;
            cin>> c>>d;
            int res=getmax(c,d);
            cout<<res<<endl;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
 	cin.tie(NULL);
 	cout.tie(NULL);
    solve();
    return 0;
}