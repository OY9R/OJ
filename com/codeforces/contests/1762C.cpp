#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
        ll ans=0,mul=1;
        char b=' ';
        for(int i=0;i<n;i++){
            char c;cin>>c;
            if(c==b)mul=mul*2%mod;
            else mul=1;
            b=c;
            ans=(ans+mul)%mod;
        }
		cout<<ans<<endl;
	}
	return 0;
}