
#include <bits/stdc++.h>

using namespace std;
const int N = 100001;
int n, arr[N];


void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


int solve(int arr[], int n) {

    int check[n];
    check[0] = arr[0];
    check[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        check[i] = max(check[i - 1], check[i - 2] + arr[i]);
    }
    return check[n - 1];
}


int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    input();
    cout << solve(arr, n) << endl;
    return 0;
}
