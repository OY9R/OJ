#include "bits/stdc++.h"
using namespace std;
#define ll long long
double n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	printf("%.2lf", n < 0 ? -n : n);
	return 0;
}
