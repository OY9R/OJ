#include "bits/stdc++.h"
using namespace std;
#define ll long long
double n, m, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	printf("%.3lf",n<5?2.5-n:(n<10?2-1.5*(n-3)*(n-3):n/2-1.5));
	return 0;
}
