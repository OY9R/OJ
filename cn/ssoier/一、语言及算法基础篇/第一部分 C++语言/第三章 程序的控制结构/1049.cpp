#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << ((n+1) % 2 || n == 7 ? "YES" : "NO");
	return 0;
}
