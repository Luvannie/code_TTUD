#include <iostream>
#include <vector>


using namespace std;


int n, a[21], A, B;


void input() {
    
    scanf("%d%d%d",&n,&A,&B);
    for (int i = 0; i < n; i++) {
        
        scanf("%d",&a[i]);
    }
}


int CountAB(int a[], int n, int sum, int A, int B) {
    if (n == 0) return sum >= A && sum <= B;
    return CountAB(a, n - 1, sum, A, B) +
           CountAB(a, n - 1, sum + a[n - 1], A, B);
}


int main() {
    input();
    cout << CountAB(a, n, 0, A, B) << endl;
    return 0;
}
