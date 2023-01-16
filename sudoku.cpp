#include <bits/stdc++.h>
using namespace std;
int x[9][9];
bool markR[9][10], markC[9][10], markS[3][3][10];
void solution(){
    for(int i = 0 ; i<9;i++){
        for(int j = 0; j< 9; j++){
            printf("%d ",x[i][j]);
        }printf("\n");
    }printf("-----\n");
}

bool check(int v, int r, int c){
    if((markR[r][v] || markC[c][v] || markS[r/3][c/3][v])) return false;
    return true;
}

void Try(int r, int c){
    for(int v= 1; v<= 9 ; v++){
        if(check(v,r,c)){
            x[r][c] =v;
            markR[r][v] = true;
            markC[c][v] = true;
            markS[r/3][c/3][v] = true;
            if(r==8  && c ==8 ){
                solution();
            }
            else{
                if(c == 8) Try(r+1,0);
                else Try(r,c+1);
            }
            markR[r][v] = false;
            markC[c][v] = false;
            markS[r/3][c/3][v] = false;
        }
    }
}
int main(){
    for(int v = 1; v<= 9 ; v++){
        for(int r = 0; r<= 8 ; r++) markR[r][v]=false;
        for(int c = 0; c<= 8 ; c++) markC[c][v] = false;
        for(int I = 0 ; I<=2; I++){
            for(int J = 0; J<=2; J++){
                markS[I][J][v]=false;
            }
        }
    }
    Try(0,0);
}

