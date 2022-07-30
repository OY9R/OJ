#include "bits/stdc++.h"
using namespace std;
#define ll long long
double a, b, c, p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	printf("%.3lf", sqrt(p * (p - a) * (p - b) * (p - c)));
	return 0;
}
