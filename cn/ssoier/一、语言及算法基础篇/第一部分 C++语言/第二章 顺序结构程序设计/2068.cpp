#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, x, y, a, b, c, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> x >> y;
	cout << (4 * x - y) / 2 << ' ' << (y - 2 * x) / 2 << endl;
	return 0;
}
