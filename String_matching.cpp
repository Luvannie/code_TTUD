#include <bits/stdc++.h>
using namespace std;
int last[256];
int ans;
void computelast(string p){ // last[x] la vi tri ben phai nhat xuat hien ki tu x
    for(int  c = 0; c<256; c++){
        last[c] = 0;
    }
    int k = p.length();
    for(int i =k-1;i>= 0; i--){
        if(last[p[i]]==0) last[p[i]]=i;
    }
}
int boyer_Moore(string p, string t){
    computelast(p);
    int s= 0;
    int cnt = 0;
    int N = t.length();
    int M=p.length();
    while(s <= N-M){
        int j = M-1;
        while (j>= 0 && t[j+s]==p[j]) // vong while so sanh 2 xau ki tu
        {
            /* code */
            j=j-1;
        }
        if(j==-1){
            cnt++;
            s= s+1;
        }
        else{
            int k =last[t[j+s]];
            s= s + (j-k > 1 ? j-k : 1); // doan truot khi gap ki tu toi 
        }
        
    }
    return cnt;
}

int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string P, T;
    getline(cin,P);
    getline(cin,T);
    int ans = boyer_Moore(P,T);
    cout<< ans<< endl;
}