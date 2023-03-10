#include <bits/stdc++.h>

using namespace std;
const int a= 1e5+1;
int A[101][101];
int N,M;
int b[50];
queue<string> D;

void input(){
    cin>> N;
    for(int i =1; i<=N;i++){
        for(int j =1; j<=N; j++){
            cin >> A[i][j];
        }
    }
    cin>> M;
    for(int i=1; i<=M; i++){
        string c;
        cin>> c;
        D.push(c);
    }
}

int main(){
    input();
    int count =0;
    for(int i =0; i<M; i++){
        string c= D.front();
        D.pop();        
        for(int j =1; j<=N; j++){
            string s=" ";
            for(int k = 1; k<= N; k++){
                 s= s+char(A[j][k]+'0');
                
            }
            size_t found = s.find(c);
            if(found != string::npos){
                count++;
                                break;
            }
        }
        
    }
    cout<<endl<<count;
    return 0;
}