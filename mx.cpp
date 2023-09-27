#include <iostream>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
long long n, a[1000005], sum;
int main() {
	freopen("pair.in", "r", stdin);
	freopen("pair.out", "w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        long long t;
        cin >> t;
        a[i] = abs(t);
    }
    sort(a+1, a+n+1);
    vector<long long> b,c;
    int cnt=1;
    for(int i=2; i<=n; i++) {
        if(a[i] == a[i-1]) {
            cnt++;
        } else {
            b.push_back(cnt);
            c.push_back(a[i-1]);
            cnt=1;
        }
    }
    b.push_back(cnt);
    c.push_back(a[n]);
    for(int i=1;i<c.size();i++) {
        if(c[i] == c[i-1]+1) {
            sum += b[i]*b[i-1];
        }
    }
    //2 3 6 7 8 10
    cout << sum;
    return 0;
}
