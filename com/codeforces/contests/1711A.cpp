#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		cout << n;
		for(int i=2;i<=n;i++){
			cout << ' ' << i-1;
		}
		cout << endl;
	}
	return 0;
}
