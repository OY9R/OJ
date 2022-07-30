#include "bits/stdc++.h"
using namespace std;
#define ull unsigned long long
ull n, m, o;
// 85 17/20
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin >> n){
		m = n;
		o = 2;
		while(m & (m + 1)){
			m /= 2;
			o *= 2;
		}
		m /= 2;
		
		cout << (n - m * o) * (m + 1) + m << endl;
	}
	return 0;
}
