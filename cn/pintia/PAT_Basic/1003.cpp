#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int p=0,a=0,t=0;
		string s;
		cin>>s;
		int i=0;
		while(i<s.length()&&s[i]=='A'){
			i++;
			p++;
		}
		if(i==s.length()||s[i++]!='P'){
			cout<<"NO"<<endl;
			continue;
		}
		while(i<s.length()&&s[i]=='A'){
			i++;
			a++;
		}
		if(i==s.length()||s[i++]!='T'){
			cout<<"NO"<<endl;
			continue;
		}
		while(i<s.length()&&s[i]=='A'){
			i++;
			t++;
		}
		if(i!=s.length()||a<1||t<p*a){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
	return 0;
}

