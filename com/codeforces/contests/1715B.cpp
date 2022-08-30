#include "bits/stdc++.h"
using namespace std;
#define ll long long
int i,j,k,l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n,k,b,s;
		cin>>n>>k>>b>>s;
		if(b*k>s||s>n*(k-1)+k*b){
			cout<<-1<<endl;
		}else{
			ll a=s-k*b;
			for(ll i=0;i<n;i++){
				ll tmp=0;
				if(i==0){
					tmp+=k*b;
				}
				if(a>=k){
					a-=k-1;
					tmp+=k-1;
				}else{
					tmp+=a;
					a=0;
				}
				cout<<tmp<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
