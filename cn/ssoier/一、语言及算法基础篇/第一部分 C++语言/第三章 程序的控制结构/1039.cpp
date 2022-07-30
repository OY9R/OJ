#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << (n ? (n > 0 ? "positive" : "negative") : "zero");
	return 0;
}
