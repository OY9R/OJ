#include "bits/stdc++.h"
#define ll long long
using namespace std;
int r[1001],s[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>s[i];
	for(int i=1;i<=m;i++)
		cin>>r[i];
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=m;j++){
			int t;
			cin>>t;
			if(t==r[j])ans+=s[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
