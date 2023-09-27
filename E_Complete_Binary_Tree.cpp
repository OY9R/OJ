#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,x,k,ans;
void dfs(int a,int b){
	int l=a,r=a;
	while(b){
		l=l*2;r=r*2+1;b--;
		if(l>n)break;
	}
	if(r>n)r=n;
	if(l<=n)ans+=r-l+1;
}
signed main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&x,&k);
		ans=0;dfs(x,k);
		while(x>1&&k){
			if(k==1)ans++;
			if(k>1)dfs(x^1,k-2);
			x/=2;k--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}