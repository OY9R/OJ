#include "bits/stdc++.h"
using namespace std;
#define ll long long
int a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	if (a < b) {
		d = a;
		a = b;
		b = d;
	};
	if (a < c) {
		d = a;
		a = c;
		c = d;
	};
	if (b < c) {
		d = b;
		b = c;
		c = d;
	};
	cout << a << ' ' << b << ' ' << c << endl;
	return 0;
}
