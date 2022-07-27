#include "bits/stdc++.h"
using namespace std;
#define ll long long
double r;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r;
	printf("%.4lf %.4lf %.4lf", r * 2, M_PI * r * 2, M_PI * r * r);
	return 0;
}
