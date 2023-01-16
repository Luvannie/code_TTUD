#include <bits/stdc++.h>
using namespace std;
map <string, int > transaction, money;
priority_queue<string,vector<int>,greater<string>> list_accounts;
bool check_account(string s ){
	while
}
int main (){
	ios_base::sync_with_stdio(0);
	 cin.tie(NULL);
	 cout.tie(NULL); 
     string type;
     int total_trans = 0;
	 int total_money_trans =0; 
	do{
	 	cin >> type;
		if (type == "#") continue;
		++total_trans;
		string from_account,to_account,time_point,atm;
		int money;
		cin >> from_account >> to_account >> money >> time_point >> atm;		
		transaction[from_account]++;
		money[from_account]+= money;
		list_accounts.push(from_account);
	 } while (type!="#");
	 do{
	 	cin >> type;
	 	if (type == "#") continue;
	 	if (type == "?check_phone_number"){
	 		if (incorrectPhone == 0) cout << 1 << endl;
	 		else cout << 0 <<endl;
		 }
		else if(type == "?number_calls_from"){
			string phone;
			cin >> phone;
			cout << numberCalls[phone] << endl;
		}
		else if (type == "?number_total_calls"){
			cout << totalCalls << endl;
		}
		else if (type == "?count_time_calls_from"){
			string phone;
			cin >> phone;
			cout << timeCall[phone] << endl;
		}
	 }
	 while (type != "#");
	 return 0;
}
}
