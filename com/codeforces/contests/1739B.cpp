#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int a[N],b[N];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		b[0]=a[0];
		int i;
		for(i=1; i<n; i++) {
			if(b[i-1]>=a[i]&&a[i]!=0)
				break;
			b[i]=b[i-1]+a[i];
		}
		if(i!=n)
			cout<<-1<<endl;else {
			for(int i=0; i<n; i++)
				cout<<b[i]<<' ';
			cout<<endl;
		}
	}
	return 0;
}