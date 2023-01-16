#include <bits/stdc++.h>
using namespace std;
int main (){
	int count =0;
	int n;
	scanf("%d",&n);
	for(int i =1; i<=9;i++){
		for(int c = 1; c<=9; c++){
			if(c==i) continue;
			for(int k =1; k<=9; k++){
				if(k==i || k== c) continue;
				for(int h =1; h<=9; h++){
					if(h==k || h==i || h==c) continue;
					for(int u =1; u<=9;u++){
						if(u== i|| u==c || u== k || u==h) continue;
						for(int s =1; s<=9;s++){
							if( s==i || s== c || s==k || s== h || s==u) continue;
							for(int t =1; t<=9;t++){
								if(t==i|| t==c || t== k || t==h || t== u || t==s) continue;
								if(i*100 +c*10 + t - k*100 -62 + h*1000 + u*100 + s*10 +t==n){
									count++;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d",count);
}
