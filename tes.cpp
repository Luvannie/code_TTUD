#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    for( int a= 1; a<=9;a++){
        for(int b=1 ;b<=9;b++){
            if(b>=a){
                for(int c =1; c<=9;c++){
                    if(c>b){
                        for(int d =1; d<=9;d++){
                            if(d>=c){
                                for(int e =1; e<=9;e++){
                                    if(e>=d){
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}