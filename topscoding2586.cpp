#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n, a[100005], b[100005], c[100005], cnt;
int main() {
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> b[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> c[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    for(int i=1;i<=n;i++){
        int l = lower_bound(a + 1, a + n + 1, b[i]) - a;
        int r = upper_bound(c + 1, c + n + 1, b[i]) - c;
        cnt += (l - 1) * (n - r + 1);
    }
    cout << cnt;
    return 0;
}
