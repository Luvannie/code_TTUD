#include <bits/stdc++.h>
using namespace std;
#define inf 10000000
int a[inf]={0}, n;

void input(){
	scanf("%d",&n);
	for(int i = 1; i<=n;i++){
		scanf("%d",&a[i]);
	}
}
int maxleft ( int i , int j ){
	int maxLM = a[j];
	int s = 0;
	for ( int k = j; k >= i; k--){
		s += a [k ];
		maxLM = max ( maxLM ,s );
	}
	return maxLM ;
}

int maxright ( int i , int j ){
	int maxRM = a[i];
	int s = 0;
	for ( int k = i; k <= j; k ++){
		s += a [k ];
		maxRM = max ( maxRM ,s );
	}
	return maxRM ;
}

int maxsubsequene(int L, int R) {
	if(L==R){
	 return a[L];
	}
	int m = (L+R)/2;
	int wL = maxsubsequene(L,m);
	int wR = maxsubsequene(m+1,R);
	int wLR = maxleft(L,m) + maxright(m+1,R);
	return max(max(wL,wR),wLR);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL); 
	input();
	int result= maxsubsequene(1,n);
	cout<< result;
	return 0;
}
