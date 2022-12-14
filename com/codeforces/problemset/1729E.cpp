#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

long long ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    long long x; cin >> x;
    return x;
}

long long solve() {
    for (int i = 2; i <= 26; i++) {
        long long x = ask(1, i);
        long long y = ask(i, 1);
        if (x == -1) return i-1;
        if (x != y) return x + y;
    }
    assert(false);
}

int main() {
    long long ans = solve();
    cout << "! " << ans << endl;
}