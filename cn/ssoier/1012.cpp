#include "bits/stdc++.h"
using namespace std;
#define ll long long
double x, a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> x >> a >> b >> c >> d;
	printf("%.7lf", a * x * x * x + b * x * x + c * x + d);
	return 0;
}
