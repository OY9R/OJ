#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n,i=1;
		cin>>n;
		while(n/i>0){
			if(n/i%10>4){
				i*=10;
				n=n+i-n%i;
			}else{
				i*=10;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
