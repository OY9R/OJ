#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<char> a;
set<char> s;
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		a.push_back(c);
		s.insert(c);
	}
	m=s.size();
	int cnt=0,ans=INT_MAX;
	map<char,int> mm;
	for(int l=1,r=1;r<=n;r++){
		if(mm[a[r-1]]==0)cnt++;
		mm[a[r-1]]=r;
		while(mm[a[l-1]]!=l)l++;
		if(cnt==m)ans=min(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}