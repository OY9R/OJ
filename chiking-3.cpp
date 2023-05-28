#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll base,a,m,n = 0;
ll qmod(ll a,ll b){
    if(b==0) return 1;
    ll ans = 1;
    while(b) {
        if(b&1) ans = (ans*a)%m;
        b>>=1;
        a = (a*a)%m;
    }
    return ans;
}
int main() {
	string a_,m_,n_;
	cin >> base >> a_ >> m_ >> n_;
	for(int i = 0; i<a_.length(); i++)
		a = a*base+a_[i]-'0';
	for(int i = 0; i<m_.length(); i++)
		m = m*base+m_[i]-'0';
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    vector<ll> q(base+1);
    for(int i=0;i<=base;i++)q[i]=qmod(a,i);
    ll ans=q[n_[0]-'0'];
	for(int i = 1; i<n_.length(); i++){
        ans=qmod(ans,base);
        ans=(ans*q[n_[i]-'0'])%m;
    }
    // cout<<ans<<endl;
	string ans_ = "";
	while(ans){
		ans_ = (char)(ans%base+'0')+ans_;
		ans/=base;
	}
	cout << ans_ << endl;
    return 0;
}