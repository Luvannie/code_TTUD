#include <bits/stdc++.h>
using namespace std;
const int N =1e5;
int m;
stack<int> A[N];

void input(){
    cin  >> m;
    for(int i =1 ; i<= m; i++){
        int deg, heso;
        cin>> deg;
        for(int j =0; j<=deg; j++) {
            cin >> heso;
            A[i].push(heso);
        }
    }
}

void output(){
    for(int i =1; i<= m ; i++){
        cout<<" da thuc thu " << i <<endl;
        int d = A[i].size();
        for(int j =0; j < d ; j ++){
            int b = A[i].top();
            
            A[i].pop();
            cout << b<< "*x^"<<j<<" ";
        }
        cout<< endl;
    }
}

int main(){
    input();
    output();
    return 0;
}