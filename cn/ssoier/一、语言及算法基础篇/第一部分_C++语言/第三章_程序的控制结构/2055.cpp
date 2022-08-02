#include "bits/stdc++.h"
using namespace std;
#define ll long long
double a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a;
	printf("%.2lf", a>20 ? a*1.98 : a*1.68);
	return 0;
}
