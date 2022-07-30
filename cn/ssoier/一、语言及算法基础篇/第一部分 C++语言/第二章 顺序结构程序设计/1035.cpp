#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x;
	printf("%d", n+(m-n)*(x-1));
	return 0;
}
