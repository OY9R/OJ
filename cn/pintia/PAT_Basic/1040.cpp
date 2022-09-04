#include "bits/stdc++.h"
#define ll long long
#define mod 1000000007
using namespace std;
int num[3];
ll ans=0;
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]=='T')
			num[2]++;
	}
	for(int i=0;i<str.length();i++){
		if(str[i]=='P')
			num[0]++;
		if(str[i]=='A')
			ans=(ans+(num[0]*num[2])%mod)%mod;
		if(str[i]=='T')
			num[2]--;
	}
	cout<<ans<<endl;
	return 0;
 } 