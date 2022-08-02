#include "bits/stdc++.h"
using namespace std;
#define ll long long
double n, m, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << (50 + n / 3 == n / 1.2 ? "All" : (50 + n / 3 < n / 1.2 ? "Bike" : "Walk"));
	return 0;
}
