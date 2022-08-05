#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, ans, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		if(n<0)n=-n;
		if(n==1||n==0)ans=n+1;
		else ans=(n+2)/3;
		cout << ans << endl;
	}
	return 0;
}
