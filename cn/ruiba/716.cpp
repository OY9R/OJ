#include "bits/stdc++.h"
#define ll long long
#define N 1<<25
using namespace std;
bool a[N],b[N],no[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,t;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>t;
		a[t]=true;
	}
	for(ll i=2;i<=m;i++)
		for(ll j=i;j<=1e7;j+=i)
			if(a[j]){
				b[i]=true;
				break;
			}
	ll ans=m;
	for(ll i=2;i<=m;i++)
		if(b[i])
			for(ll j=i;j<=m;j+=i)
				if(!no[j]){
					no[j]=true;
					ans--;
				}
	printf("%d\n",ans);
	for(ll i=1;i<=m;i++)
		if(!no[i])
			printf("%d\n",i);
	return 0;
}
