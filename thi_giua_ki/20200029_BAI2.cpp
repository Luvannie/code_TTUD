#include<bits/stdc++.h>
#include<vector>
#define MAX 100001
using namespace std;

int n;
int a[MAX];
int deleteMax(){
	int max = 0;
		
	for(int i = 0; i < n; i++)			//Find max
		if(a[i] >= max) max = a[i];
		
	for(int i = 0; i < n; i++){
		if(a[i] == max){				//Found max	
			for(int j = i; j < n; j++)
				a[j] = a[j+1];
			n--;

			return max;
		}
	}
	return max;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int v;
	for(int i = 0; i < n; i++) 	cin >> a[i];
	
	string type;
	do{
		cin >> type;
	
		if(type == "insert"){
			int num; 
			cin >> num;
			a[n] = num;
			n++;
		}
			
		if(type == "delete-max"){
			cout << deleteMax() << endl;
		}	
			
	}while(type != "*");
}
