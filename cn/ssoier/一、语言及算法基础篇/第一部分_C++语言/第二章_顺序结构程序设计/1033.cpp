#include "bits/stdc++.h"
using namespace std;
#define ll long long
double n, m, x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x >> y;
	printf("%.3lf", sqrt((x-n)*(x-n)+(y-m)*(y-m)));
	return 0;
}
