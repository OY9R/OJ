#include "bits/stdc++.h"
using namespace std;
#define ll long long
double r1, r2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r1 >> r2;
	printf("%.2lf", 1 / (1 / r1 + 1 / r2));
	return 0;
}
