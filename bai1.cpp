// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1000001;
// int n, a[N];
// int res = 1;
// int index = 1;
// void input(){
//     cin>> n;
//     for(int i =1; i<=n;i ++){
//         cin>> a[i];
//     }
// }

// void solve(int index){
//     //if(index == n) break;
//     int count =1;
//     for(int i = index+1; i<= n;i++){
//         if(a[i] > a[i-1]){
//             count+=1;
//         }else{
//             index= i;
//             if( count > res){
//                 res= count;
//             }
//             solve(index);
//         }
//     }
// }

// int main(){
//     input();
//     solve(1);
//     cout<<res;
//     return 0;
// }

#include <stdio.h>
int main(){
    int a[100];
    int n;
    scanf("%d\n",&n);

    for (int i=0; i<n;i++){
        scanf("%d",&a[i]);
        }
    int count =0 ;
    int max =1;
    for (int i=1; i<n;i++){
        if (a[i-1] <a[i]){
        count=count+1;
        if (count>max){
            max=count;
            }
        }else{
            count=1;
        }
    }
    printf("%d", max);
}