#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define maxn 200000
int n, m;
int main() {
	cin >> n >> m;
	if (n % 2) {
	} else {
		for (int i = 1; i <= n / 2 - m; i++) {
			cout << 'A';
		}
		for (int i = 1; i <= m; i++) {
			cout << "BA";
		}
		for (int i = 1; i <= n / 2 - m; i++) {
			cout << 'B';
		}
	}
	return 0;
}
