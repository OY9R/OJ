#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, x, y, a, b, c, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> x >> a >> y >> b;
	printf("%.2f", (x * a - y * b) / (float)(a - b));
	return 0;
}
