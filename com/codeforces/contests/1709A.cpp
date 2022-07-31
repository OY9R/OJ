#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, k, m;
int doors[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> k;
		for(int i=1;i<=3;i++){
			cin >> doors[i];
		}
		m = 0;
		while(doors[k]!=0){
			k=doors[k];
			m++;
		}
		if(m==2) {
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}
