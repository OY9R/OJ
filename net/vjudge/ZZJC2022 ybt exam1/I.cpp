#include<bits/stdc++.h>
using namespace std;
int main() {
	string s,ans;
	getline(cin,s);
	for(int i=1;i<s.size();i++){
		ans+=s[i-1]+s[i];
	}
	ans+=s[0]+s[s.size()-1];
	cout<<ans<<'\n';
	return 0;
}