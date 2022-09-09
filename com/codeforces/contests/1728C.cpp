#include<bits/stdc++.h>
using namespace std;
const int N=200002;
int a[N],b[N];
int an[10],bn[10];
int tenlog(int a) {
	int n=0;
	while(a) {
		a/=10;
		n++;
	}
	return n;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		memset(an,0,sizeof(int)*10);
		memset(bn,0,sizeof(int)*10);
		int n,ans=0;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		for(int i=0; i<n; i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0; i<n; i++) {
			if(a[i]<10)
				an[a[i]]++;
			else {
				int ii=lower_bound(b,b+n,a[i])-b;
				if(ii<n&&b[ii]==a[i]) {
					b[ii]=0;
					a[i]=0;
				} else {
					an[tenlog(a[i])]++;
					ans++;
				}
			}
		}
		for(int i=0; i<n; i++) {
			if(b[i]<10)
				bn[b[i]]++;
			else {
				int ii=lower_bound(a,a+n,b[i])-a;
				if(ii<n&&b[i]==a[ii]) {
					b[i]=0;
					a[ii]=0;
				} else {
					bn[tenlog(b[i])]++;
					ans++;
				}
			}
		}
		for(int i=2; i<=9; i++)
			ans+=abs(an[i]-bn[i]);
		cout<<ans<<endl;
	}
	return 0;
}
