#include "bits/stdc++.h"
using namespace std;
int n,k,ans;
long m[21];
bool isPrime(int n){
	if(n==2)return true;
	if(n%2==0)return false;
	for(int i=3;i<=sqrt(n);i+=2)
		if(n%i==0)
			return false;
	return true;
}
void dfs(int u,int sum,int end){
    if(end==0)ans+=isPrime(sum);
    else for(int i=u;i<=n-end;++i)
        dfs(i+1, sum+m[i], end-1);
}
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>m[i];
    dfs(0,0,k);
    cout<<ans;
    return 0;
}
