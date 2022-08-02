#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	cin >> n >> c;
	cout << 8+(n>1000?((n-1001)/500+1)*4:0)+(c=='y'?5:0);
	return 0;
}
