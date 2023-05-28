#include <bits/stdc++.h>
using namespace std;
const int p= 1000000007;
void solve() {
    int n, m;
    long long ANS= 0;
    cin >> n >> m;
    int a[n + 1];
    long long f[64]= {}, ans[64]= {};
    for(int i= 1; i <= n; i++)
        cin >> a[i];
    ans[63]= 1;
    for(int i= 1; i <= n; i++) {
        for(int j= 0; j < 64; j++)
            f[a[i] & j]= (f[a[i] & j] + ans[j]) % p;
        for(int j= 0; j < 64; j++) {
            ans[j]+= f[j];
            f[j]= 0;
        }
    }
    for(int i= 0; i < 64; i++)
        if(__builtin_popcount(i) == m)
            ANS= (ANS + ans[i]) % p;
    cout << ANS - (m == 6) << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}