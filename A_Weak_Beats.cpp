#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve(){
	string s;cin>>s;
	int n=s.size();
    for(int i=1;i<n;i+=2)
        if(s[i]!='0')
            return cout<<"No"<<endl,void();
    cout<<"Yes"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}