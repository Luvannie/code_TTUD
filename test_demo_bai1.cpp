#include <bits/stdc++.h>
using namespace std;
const int  N= 1000002;
int n, a[N];

void input(){
	scanf("%d",&n);
	for(int i = 1; i<= n; i++) scanf("%d",&a[i]);
}

void solve(){
	int res = 0;
	for(int i =2; i<=n-1;i++ ){
		if(a[i]>a[i-1] && a[i]>a[i+1]){
			res++;
		}
	}
	printf("%d",res);
}
int main(){
	input();
	solve();
	return 0;
}
