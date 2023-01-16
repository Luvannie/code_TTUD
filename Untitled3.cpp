#include <bits/stdc++.h>
using namespace std;
const int  N = 1e9 +2;
int T=20;
int n,a[N],c;
void input(){
	scanf("%d",&n);
	for(int i = 1; i<= n; i++){
		scanf("%d",&a[i]);
	}
}

bool check(int d){
	int cnt = 1, last = 1;
		for(int i = 2; i <= n; ++ i)
		if(a[i] >= a[last] + d){
			++ cnt;
			last = i;
		}
		if (cnt >= c) return true;
		return false;
}
void proc2(){
	sort(a+1,a+n+1);
	int l = 1, r = (a[n]-a[1])/(c-1), mid, res = 1;
	while(l <= r){
		mid = (l + r)/2;
		if(check(mid) == true) l = mid + l, res = mid;
		else r = mid - l;
	}

	cout << res << endl;
}

int main(){
	input();
	proc2();
	return 0;
}

