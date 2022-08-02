#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << (n % 3 || n % 5 ? "NO" : "YES");
	return 0;
}
