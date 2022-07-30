#include "bits/stdc++.h"
using namespace std;
#define ll unsigned long long
#define maxn 100001

const ll mod = 1e9+7;
ll t, m[maxn],tmp;
int n;
ll gcd (ll a, ll b) {
	if (!a||!b) return 0;
	return a % b ? gcd(b, a % b) : b;
}
int main() {
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> m[i];
		}
		ll t1 = gcd(m[0], m[1]);
		ll t2 = gcd(t1, m[2]);
		if (t2 < t1) {
		} else if (gcd(m[0], m[2]) > t2) {
			t1 = gcd(m[0], m[2]);
		} else {
			t1 = gcd(m[1], m[2]);
		}
		for(int i=3;i<n;i++){
			tmp = gcd(m[i], t1);
			if (tmp >= t2) {
				t1 = tmp;
			} else {
				t1 = t2;
				t2 = tmp;
			}
		}
		cout << t1 << endl;
	}
	return 0;
}
