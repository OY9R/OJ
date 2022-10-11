#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200002],b[200002];
int main() {
	cin>>a[0];
	for(int i=1;i<=a[0];i++)
		cin>>a[i];
	cin>>b[0];
	for(int i=1;i<=b[0];i++)
		cin>>b[i];
	int ai=1,bi=1;
	while((ai+bi)*2<=a[0]+b[0]+(a[0]+b[0])%2){
		if(ai>a[0])bi++;
		else if(bi>b[0])ai++;
		else if(a[ai]>b[bi])bi++;
		else ai++;
	}
	ll ans;
	if(ai>a[0])ans=b[bi];
	else if(bi>b[0])ans=a[ai];
	else if(a[ai]>b[bi])ans=b[bi];
	else ans=a[ai];
	cout<<ans<<endl;
	return 0;
}