#include<bits/stdc++.h>
using namespace std;
int n,tmp;
long long ans=1;
vector<int> a,b;
void solve() {
	cin>>n;
	a.resize(n);
	b.resize(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	b[0]=1;
	for(int i=1; i<n; i++) {
		if(a[i]>=b[i-1]+1) b[i]=b[i-1]+1;
		else b[i]=a[i];
		ans+=b[i];
	}
	//cout<<ans<<endl;
}
void solve2() {
	int p,x;
	long long nans=ans;
	cin>>p>>x;
	p--;
	if(p==0) {
		cout<<ans<<endl;
		return;
	}
	vector<int> db(n);
	db[p-1]=b[p-1];
	tmp=a[p],a[p]=x;
	for(int i=p; i<n; i++) {
		int now;
		if(a[i]>=db[i-1]+1)now=db[i-1]+1;
		else now=a[i];
		if(now==b[i])break;
		db[i]=now;
		nans+=db[i]-b[i];
	}
	a[p]=tmp;
	cout<<nans<<endl;
}
int main() {
	solve();
	int _;
	cin>>_;
	while(_--)
		solve2();
	return 0;
}