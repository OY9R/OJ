#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, x, y, a, b, c, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b >> c >> x >> y;
	a = a / 3;
	b = (b + a) / 3;
	c = (b + c) / 3;
	x = (c + x) / 3;
	y = (x + y + a) / 3;
	a += b + y;
	b += c;
	c += x;
	x += y;
	printf("%5d%5d%5d%5d%5d", a, b, c, x, y);
	return 0;
}
