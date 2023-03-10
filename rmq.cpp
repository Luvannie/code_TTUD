#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int n, m, log2n, a[N], rmq[N][20];

void build_rmq_table() {
    log2n = log2(n);
    for (int i = 1; i <= n; i++)
        rmq[i][0] = a[i];
    for (int j = 1; j <= log2n; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
}

int rmq_query(int l, int r) {
    int k = log2(r - l + 1);
    return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build_rmq_table();
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << rmq_query(l, r) << endl;
    }
    return 0;
}
