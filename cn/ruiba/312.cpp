#include "bits/stdc++.h"
using namespace std;
#define ll __int64
#define maxn 2000
ll x;
int n;
int main() {
	n=10;
	while(++n <= 11){
		x = 3778888999;
		int i = 0;
		while(i != n){
			x++;
			ll m = x;
			i = 0;
			while(m >= 10){
				ll t = m;
				m = 1;
				while(t > 0){
					m *= t % 10;
					t /= 10;
				}
				i++;
			}
		}
		cout << n << " " << x << endl;
	}
	return 0;
}
