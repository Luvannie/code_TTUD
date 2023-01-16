# include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n,K; // N la so khach hang, K la so xe
int d[N];
int Q ; // Q la tai trong cua xe, cac xe la nhu nhau
int c[N][N]; // ma tran khoang cach cua cac khach hang
bool visited[N]; // danh dau mot diem da tham hay chua
// data structures for exhaustive search
int y[N]; // y[k] la diem dau tien ma xe k di toi
int x[N];// x[v] l� diem tiep theo sau khi di toi v
int load[N]; // ghi nhan luong hang hoa tren lo trinh xe thu k
int f;
int nbSegment;
int f_min;
int cmin;


bool checkX(int v, int u ,int k){ // kiem tra xem gia tri v co the gan cho x[u] tren lo trinh xe k hay khong
	if(v== 0 ) return true; // neu do la diem 0. luon dung, tuc la xe ve lai kho
	if(load[k]+ d[v] > Q) return false; // qua tai trong
	if(visited[v]==true) return false; // diem nay da duoc di qua
	return true;
}

bool checkY(int v, int k){ // kiem tra xem xe k co di duoc toi dia diem v khong
	if(load[k] + d[v] >Q) return false;
	if(visited[v]==true) return false;
	return true;
}

void solution(){
	if(f< f_min){
		f_min = f;
	}
	/*for(int k =1; k<= K; k++){
		cout << "Route[" << k << "]: 0";
		int v=y[k];
		while(v> 0 ){
			cout<< "-" << v;
			v=x[v];
		}
		cout<<"- 0"<<endl;
	}
	cout<< "-----------------"<<endl;*/
}

void TryX(int i, int k){ // thu cac gia tri x[u] tren lo trinh xe k
	for ( int v= 0 ; v<= n;v++){
		if(checkX(v,i,k)){
			//cout<< 3<< endl;
			x[i]=v;
			visited[v]= true;
			nbSegment += 1;
			load[k]+= d[v]; 
			f+= c[i][v];
			if(v==0){ // quay ve kho
				if(k==K){ // tat ca xe deu di het
					if(nbSegment == n + K){ // moi diem v deu duoc giao hang
						solution();
					}
				}else{
					if(f + cmin*(n+K-nbSegment) < f_min)TryX(y[k+1],k+1);
					}
				
			}else{ // v la khach hang
					TryX(v,k); // tim khach hang tiep theo tren lo trinh v
				}
			// khoi phuc trang thai
			visited[v]=false;
			nbSegment-=1;
			load[k]-=d[v];
			f-=c[i][v];
		}
	}
}

void TryY(int k){ // thu gia tri cho y[k]
	for (int v= y[k-1]+1; v<=n-K +k; v++){// vi ta gia su y[1] < y[2] <...< y[k]
		if(checkY(v,k)){
			//cout<<"1"<<endl;
			y[k] = v; // chon v la diem di dau
			visited[v] = true; // danh dau diem v la da duoc di qua
			nbSegment +=1; // tang so luong chuyen di
			f+=c[0][v];
			load[k]+= d[v]; // them tai trong hang cua khach hang v
			if (k==K){
				//cout<<2<< endl;
				TryX(y[1],1);// bat dau thu duyet lo trinh xe 1
			}
			else{
				TryY(k+1);
			}
			// khoi phuc trang thai
			visited[v] = false;
			nbSegment -=1;
			f-=c[0][v];
			load[k]-= d[v];
		}
	
		
		}
	}


void input(){	
	scanf("%d%d%d",&n,&K,&Q);
	for( int i = 1; i<= n; i++) cin>> d[i];
	for (int i = 0; i<= n ; i++){
		for ( int j = 0; j<=n ; j++){
			scanf("%d",&c[i][j]);
			if(cmin > c[i][j] ) cmin = c[i][j];
		}
	}
}

void solve(){
	for(int i =1; i<= n; i++) visited[i] = false;
	for(int k =1; k<=K;k++) load[k] = 0;
	nbSegment = 0;
	f_min = 1e9;
	f= 0;
	y[0] = 0;
	TryY(1);
	printf("%d",f_min);
}
int main(){
	//cout<<"CVRP" <<endl;
	input();
	solve();
	return 0;
}
