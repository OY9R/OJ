#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
bool mp[N][N];
int n,m;
int h[N],l[N],r[N];
void solve(){
	stack<int> s;
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!mp[i][j])h[j]++;
			else h[j]=0;
			while(!s.empty()&&h[s.top()]>h[j]){
				ll t=s.top();
				s.pop();
				ans+=(j-s.top()-1)*h[t];
			}
			s.push(j);
		}
		ll tt=s.top();
		while(!s.empty()){
			ll t=s.top();
			s.pop();
			if(s.empty())ans+=(tt)*h[t];
			else ans+=(tt-s.top())*h[t];
		}
	}
	cout<<ans<<endl;
}
int main(){
	cin>>n>>m;
	int a,b;
	while(m--){
		cin>>a>>b;
		mp[a][b]=1;
	}
	solve();
	return 0;
}