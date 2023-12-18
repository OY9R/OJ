#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve(){
    int n;cin>>n;
    map<ll,ll>m;
    for(int j=0;j<n;j++){
        ll size,num;cin>>size>>num; 
        m[size]=num;
    }
    ll ans=0;
    for(auto it:m){
        if(it.second>1)
            m[2*it.first]+=it.second/2;
        ans+=(it.second%2);
    }
    cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}