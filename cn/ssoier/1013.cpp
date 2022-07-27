#include "bits/stdc++.h"
using namespace std;
#define ll long long
double f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> f;
	printf("%.5lf", 5 * (f - 32) / 9);
	return 0;
}
