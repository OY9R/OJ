#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin>>n;
	if(n%2==0){
		cout<<n/2<<endl;
	}else{
		for(ll i=3;i<sqrt(n);i+=2){
			if(n%i==0){
				cout<<n/i<<endl;
				break;
			}
		}
	}
	return 0;
}