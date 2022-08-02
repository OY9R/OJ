#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << (int)(n % 4 > 1) << ' ' << n % 2 << ' ' << n / 4 - (int)(n % 4 > 1) - n % 2 ;
	return 0;
}
