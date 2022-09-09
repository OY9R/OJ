#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int m=0,mi;
		for(int i=1; i<=n; i++) {
			int in;
			cin>>in;
			if(in>m) {
				m=in;
				mi=i;
			}
		}
		cout<<mi<<endl;
	}
	return 0;
}