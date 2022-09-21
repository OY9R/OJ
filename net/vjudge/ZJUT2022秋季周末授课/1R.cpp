#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int N=5e5+100;
ll inpt[N];
ll cnt1[100];
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(cnt1,0,sizeof cnt1);
		for(int i=0;i<n;i++){
			cin>>inpt[i];
			ll m=inpt[i];
			for(int j=0;m>0;j++){
				if(m&1)cnt1[j]++;
				m>>=1;
			}
		}
		ll ans=0;
		for(int i=0;i<n;i++){
			ll m=inpt[i];
			ll num1=0,num2=0;
			for(int j=0;j<=61;j++)
				if((m>>j)&1){
					num1+=cnt1[j]*((1LL<<j)%MOD);
					num1%=MOD;
					num2+=n*((1LL<<j)%MOD);
					num2%=MOD;
				}else{
					num2+=cnt1[j]*((1LL<<j)%MOD);
					num2%=MOD;
				}
			ans+=num1*num2%MOD;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}