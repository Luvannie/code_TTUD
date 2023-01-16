#include <bits/stdc++.h>
using namespace std;
#define N 100001 
vector<int> A[N]; // danh sachs cac dinh ke dinh v
int n, m; // so dinh, canh
int cc[N]; // dinh n thuoc cc nao
int nbCC;
void input(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i =1; i<= m; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		A[u].push_back(v);
		A[v].push_back(v);
	}
}

void DFS(int u){
	cc[u]= nbCC;
	for(int i =0; i< A[u].size();i++){
		int v=A[u][i];
		if(cc[v]==0){
			DFS(v);
		}
	}
}

void DFS(){
	for(int v= 1; v<=n; v++){
		cc[v]=0;
	}
	nbCC = 0;
	for(int v= 1; v<=n;v++){
		if(cc[v]==0){
			nbCC+=1;
			DFS(v);
		}
	}
}

void printres(){
	for(int c= 1; c<=nbCC; c++){
		cout<<"connected component"<<c<<":";
		for(int v =1; v<= n; v++){
			if(cc[v]==c){
				cout<<v<<" ";
			}
		}
		cout<<endl;
	}
}
int main (){
	input();
	DFS();
	//printres();
	cout<<nbCC;
	return 0;
}
