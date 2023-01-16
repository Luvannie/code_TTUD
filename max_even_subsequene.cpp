#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 +2;
int n, a[N];
bool bc[N]={false},bl[N]={false};
int sc[N],sl[N];
void input(){
	scanf("%d",&n);
	for(int i =1; i<= n; i++) scanf("%d",&a[i]);
	
}

void setup(){
	if(a[1]%2 == 0){
		bc[1]=true;
		sc[1]= a[1];
	}
	else{
		bl[1]=true;
		sl[1]=a[1];
	}
}
void solveBottomUp(){
	int res = -(1e9);
	for(int i =2; i <= n ; i++){
			if (a[i]%2 ==0 ){
				if(bc[i-1]==true && sc[i-1]>0){
					sc[i]=sc[i-1]+a[i];
				}
				else{
					sc[i]=a[i];
				}
				bc[i]= true;
				if(bl[i-1]==true && sl[i-1]>0){
					sl[i]=sl[i-1]+a[i];
					bl[i]=true;
				}
				
			}
			else{
				if(bl[i-1]==true){
					sc[i]=sl[i-1]+ a[i];
					bc[i]=true;
				}
				if(bc[i-1]==true && sc[i-1]>0){
					sl[i]=sc[i-1]+a[i];
				}	
				else{
					sl[i]=a[i];
				}
				bl[i]=true;
			}
			res= max(res,sc[i]);
		}
	if(res > -1e9){
		printf("%d",res);
	}else{
		printf("NOT_FOUND");
	}
}
int main(){
	input();
	setup();
	solveBottomUp();
}
