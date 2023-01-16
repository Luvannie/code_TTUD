#include <bits/stdc++.h>
using namespace std;
const int N= 1e5 + 2;
typedef struct{
	int start;
	int end;
} Time;
 int n;
 
Time a[N];
bool cmp(Time A, Time B){
	if(A.end < B.end) return true;
	if(A.end ==B.end){
		if(A.start < B.start) return true;
	}
	return false;
}

void input(){
	scanf("%d", &n);
	for(int i = 1; i <=n;i++){
		scanf("%d %d",&a[i].start,&a[i].end);
	}
}

void proc(){
	sort(a+1,a+n+1,cmp);
	int last =1,result =1;
	for( int i = 2; i<= n; ++i){
		if(a[i].start > a[last].end){
			++result;
			last =i;
		}
	}
	printf("%d",result);
}

void solve(){
	
}
int main(){
	input();
	proc();
	return 0;
}
