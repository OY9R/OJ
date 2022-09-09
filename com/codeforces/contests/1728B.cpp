#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		if(n%2) {
			cout<<n-3<<' '<<n-2<<' ';
			for(int i=n-4; i>0; i--)
				cout<<i<<' ';
		} else {
			for(int i=n-2; i>0; i--)
				cout<<i<<' ';
		}
		cout<<n-1<<' '<<n<<endl;
	}
	return 0;
}