#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, h, m;
bool nn[200001];
int mm[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0;
		if (n<10) ans=n;
		else if (n<18) ans=(n-9)*10+9;
		else if (n<25) ans=(n-17)*100+89;
		else if (n<31) ans=(n-24)*1000+789;
		else if (n<36) ans=(n-30)*10000+6789;
		else if (n<40) ans=(n-35)*100000+56789;
		else if (n<43) ans=(n-39)*1000000+456789;
		else if (n<45) ans=(n-42)*10000000+3456789;
		else ans=123456789;
		cout << ans << endl;
	}
	return 0;
}
