#include <bits/stdc++.h>
#define int __int128
using namespace std;
constexpr int mod= 998244353;
long long n, s;
struct node {
    int u, v, w;
};
int ksm(int a, int b) {
    int res= 1;
    while(b) {
        if(b & 1) res= res * a % mod;
        b>>= 1;
        a= a * a % mod;
    }
    return res;
}
void solve() {
    cin >> n >> s;
    vector<node> g;
    vector<int> f(n + 1), p(n + 1);
    for(int i= 1; i <= n; i++) p[i]= i, f[i]= 1;
    auto find= [&](auto find, int x) -> int {
        if(p[x] != x) p[x]= find(find, p[x]);
        return p[x];
    };
    auto merge= [&](auto find, int u1, int v1) -> void {
        p[v1]= u1;
        f[u1]+= f[v1];
    };
    for(int i= 1; i <= n - 1; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    sort(g.begin(), g.end(), [&](auto a, auto b) { return a.w < b.w; });
    int cnt= 1;
    for(auto& [u, v, w]: g) {
        int u1= find(find, u), v1= find(find, v);
        int cnt1= ((f[u1] - 1) * (f[v1] - 1) + f[u1] - 1 + f[v1] - 1);
        int cnt2= (s - w) % mod;
        cnt*= ksm(cnt2 + 1, cnt1) % mod;
        cnt%= mod;
        merge(merge, u1, v1);
    }
    if(cnt < 0) cnt+= mod;
    long long abcde= cnt;
    cout << abcde << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long T;
    for(cin >> T; T--;)
        solve();
}