#include "bits/stdc++.h"
using namespace std;
#define ll long long
double a, b;

int main() {

	cin >> a >> b;
	while(a >= b){
		a -= b;
	}
	printf("%g", a);
	return 0;
}
