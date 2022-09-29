#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
ll res[67][67]={0};
ll C(ll n,ll m){
    if(m==0 || m==n) return 1;
    if(res[n][m] != 0)return res[n][m];
    return res[n][m] = C(n-1,m)+ C(n-1,m-1);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans=0,m=n/2;
		ll sum=C(n-1,m-1)%mod;
		while(n>0&&m>0){
			if(ans!=0)ans=(ans+C(n-1,m-1)%mod)%mod;
			if(n<6)break;
			ans=(ans+C(n-4,m-3)%mod)%mod;
			n-=4;m-=2;
		}
		cout<<(sum+ans)%mod<<' '<<(sum+mod-ans-1)%mod<<" 1"<<endl;
	}
    return 0;
}
