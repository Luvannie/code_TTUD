#include <bits/stdc++.h>
using namespace std;
#define N 10001
int n, m;
int x[N],y[N];
int S[N][N];
char trace[N][N];
void input(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i = 1; i<=n;i++){
		scanf("%d",&x[i]);
	}
	
	for(int i= 1; i<=m;i++) scanf("%d",&y[i]);
}
void solveBottomUp(){
	for( int i =0; i<=n;i++) S[i][0]=0;
	for(int i = 0; i<=m;i++) S[0][i] = 0;
	int res = 0;
	for(int i = 1; i<= n ; i++){
		for(int j =1; j<=m;j++){
			if(x[i]==y[j]){
				S[i][j] = S[i-1][j-1] + 1;
				trace[i][j]="D";
			}
			else{
				//S[i][j]=max(S[i-1][j],S[i][j-1]);
				if(S[i-1][j]>S[i][j-1]){
					S[i][j]=s[i-1][j];
					trace[i][j]="U";
				}
				else{
					S[i][j]=S[i][j-1];
					trace[i][j]="L";
				}
			}
		}
	}
	res= S[n][m];
	cout << res<< endl;
	int i =n,j=m;
	
}
int F(int i, int j){
	if(i==0 || j==0){
		S[i][j] = 0; return S[i][j];
	}
	if(S[i][j]==-1){
		if(x[i]==y[j]){
			S[i][j]= S[i-1][j-1] +1;
		}
		else{
			S[i][j] = max(F(i-1,j),F(i,j-1));
		}
	}
	return S[i][j];
}

void solveTopDown(){
	for(int i = 1; i<= n;i++){
		for(int j = 1; j<= m ; j++){
			S[i][j]=-1;
		}
	}
	int res = F(n,m);
	cout<< res;
}
int main(){
	input();
	solveBottomUp();
	//solveTopDown();
	return 0;
}
