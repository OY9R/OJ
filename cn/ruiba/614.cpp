#include "bits/stdc++.h"
using namespace std;
#define ull unsigned long long
ull n, m;
// 90 18/20
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin >> n){
		m = 0;
		while(n > 0){
			n /= 2;
			m++;
		}
		cout << m << endl;
	}
	return 0;
}
