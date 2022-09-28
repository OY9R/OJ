#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100100;
ll a[N],b[N],c[N];
int main(){
	int n,m;
	cin>>n>>m;
	fill(c,c+n,INT_MAX);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	int i=0,j=0;
	ll ans=0;
	while(i<n){
		while(j<m&&b[j]<a[i])j++;
		ll tmp=INT_MAX;
		if(j>0) tmp=min(tmp,a[i]-b[j-1]);
		if(j<m) tmp=min(tmp,b[j]-a[i]);
		ans=max(ans,tmp);
		i++;
	}
	cout<<ans<<endl;
	return 0;
}//Shaoxing--binary
