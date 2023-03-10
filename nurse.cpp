#include <bits/stdc++.h>
const int MAX = 2000;
using namespace std;
int N, K1, K2;
void solve()
{
    int S0[MAX], S1[MAX];
    /*S0[i] la so phuong an thoa man de bai trong i ngay voi ngay i la ngay nghi
     S1[i] la so phuong an thoa man de bai trong i ngay voi ngay i la ngay  di lam*/
    // khoi tao
    S0[0] = 1;
    S0[1] = 1;
    S1[K1] = 1;
    for (int i = K1 + 1; i <= N; i++)
    {
        S0[i] = S1[i - 1]; // vi neu i la ngay nghi thi i-1 phai la ngay lam viec
        S1[i] = 0;
        for (int j = K1; j <= K2; j++)
        {
            if (i - j >= 0)
            {
                S1[i] = S1[i] + S0[i - j]; 
                /*
                S1[i] = tong sigma chay tu max(0,i-K2) toi K1 cua S0[j]
                */
            }
        }
    }
    int ans = S0[N] + S1[N];
    cout << ans;
}

void input()
{
    cin >> N >> K1 >> K2;
}
int main()
{
    input();
    solve();
}