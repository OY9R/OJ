#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define maxn 2000
int t, x, y, z;

int main() {
	cin >> t;
	while (t--) {
		cin >> x >> y >> z;
		if (x == y && x == z) {
			cout << "ping" << endl;
		} else {
			cout << "xiaohe" << endl;
		}
	}
	return 0;
}
