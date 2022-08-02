#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x >> y;
	printf("%d", max(n - y / x - (bool)(y % x), 0));
	return 0;
}
