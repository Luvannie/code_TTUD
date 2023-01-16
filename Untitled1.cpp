#include <bits/stdc++.h>
using namespace std;
int mystery(int a, int * b, int& c){
	a++;
	(*b)++;
	c++;
	return a;
}

int main(){
	int a= 0,  b=0,  c= 0,  d=2;
	mystery(a,&b,c);
	cout<<a<<" "<<b<<" "<<c<<" "<<d<< endl;
	d=mystery(a,&a,a);
	cout<<a<<" "<<b<<" "<<c<<" "<<d<< endl;
	return 0;
}
