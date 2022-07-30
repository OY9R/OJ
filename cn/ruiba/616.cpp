#include "bits/stdc++.h"
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll n, m;
ll mpow(ll x, ll y) {
	if(!y){
		return 1;
	}
	ll tmp = mpow(x, y / 2);
	tmp = tmp * tmp % mod;
	if (y % 2) {
		return tmp * x % mod;
	} else {
		return tmp;
	}
}
int main() {
	// (2^n-1)^m
	while(cin >> n >> m){
		cout << mpow(mpow(2, n) - 1, m) << endl;
	}
	return 0;
}
