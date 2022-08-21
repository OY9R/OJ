#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, ans, m[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		cout << n << endl;
		for(int i=1;i<=n;i++){
			m[i]=i;
			cout<<m[i]<<' ';
		}
		cout<<endl;
		swap(m[1],m[n]);
		for(int i=n;i>1;i--){
			for(int j=1;j<=n;j++){
				cout<<m[j]<<' ';
			}
			cout<<endl;
			swap(m[i-1],m[i]);
		}
	}
	return 0;
}
