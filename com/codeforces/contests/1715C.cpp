#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define MAXN 100009
ll a[MAXN],b[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		b[i]=(ll)i*(n-i);
	ll ans=(ll)n*(n+1)*(n+2)/6;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			ans-=b[i];
		}
	}
	while(m--){
		int i;
		ll x;
		cin>>i>>x;
		if(i<n&&a[i]==a[i+1]&&x!=a[i+1])ans+=b[i];
		else if(i<n&&a[i]!=a[i+1]&&x==a[i+1])ans-=b[i];
		if(i>1&&a[i]==a[i-1]&&x!=a[i-1])ans+=b[i-1];
		else if(i>1&&a[i]!=a[i-1]&&x==a[i-1])ans-=b[i-1];
		a[i]=x;
		cout<<ans<<endl;
	}
	return 0;
}
