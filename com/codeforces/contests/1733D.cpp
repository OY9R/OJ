#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y>>s;
		x=min(x,y*2);
		int len=s.length();
		int c1=0;
		for(int i=0;i<len;i++){
			char c;
			cin>>c;
			if(s[i]!=c){
				s[i]='1';
				c1++;
			}else s[i]='0';
		}
		if(c1&1){
			cout<<-1<<endl;
			continue;
		}
		ll cost=0;
		bool flag=false;
		for(int i=1;i<len;i++){
			if(s[i]=='1'&&s[i-1]=='1'&&c1==2){
				flag=true;
				cout<<x<<endl;
				break;
			}
		}
		if(flag)continue;
		cost=(c1/2)*y;
		cout<<cost<<endl;
	}
	return 0;
}