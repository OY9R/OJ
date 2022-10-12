#include "bits/stdc++.h"
using namespace std;
vector<int> a;
int cnt=0;
pair<int,int> dfs(int l,int r) {
	if(r-l==2) {
		if(a[l]==a[l+1]+1){
			cnt++;
			return {a[l+1],a[l]};
		}
		if(a[l]+1==a[l+1])
			return {a[l],a[l+1]};
		return {-1,-1};
	}
	int mid=(l+r)/2;
	auto ll=dfs(l,mid);
	auto rr=dfs(mid,r);
	if(ll.first==-1||rr.first==-1)
		return ll;
	if(rr.second<ll.first) {
		cnt++;
		return {rr.first,ll.second};
	}
	if(ll.second<rr.first) {
		return {ll.first,rr.second};
	}
	return {-1,-1};
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		a.resize(n+1);
		for(int i=1; i<=n; i++)
			cin>>a[i];
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		cnt=0;
		auto res = dfs(1,n+1);
		if(res.first==-1)
			cout<<-1<<endl;
		else
			cout<<cnt<<endl;
	}
	return 0;
}
