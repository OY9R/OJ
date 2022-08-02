#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cout << ((n < 60) + (m < 60)) % 2;
	return 0;
}
