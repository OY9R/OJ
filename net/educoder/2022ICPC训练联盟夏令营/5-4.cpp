#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=101;
int m[MAXN],n[MAXN];
ll s[MAXN],g[MAXN];
void dfs(int id,ll B) {
	g[id]+=B*s[id];
	if(m[id]) {
		id=m[id];
		dfs(id,B);
		while(n[id]!=0) {
			id=n[id];
			dfs(id,B);
		}
	}
}
int main() {
	int N,w=1;
	ll S;
	cin>>N>>S;
	for(int i=0; i<MAXN; i++)
		s[i]=S;
	while(N--) {
		int o,id;
		cin>>o>>id;
		if(o==1)
			if(m[id]) {
				id=m[id];
				while(n[id]!=0)
					id=n[id];
				n[id]=++w;
			} else
				m[id]=++w;
		else if(o==2)
			cin>>s[id];
		else if(o==3) {
			ll B;
			cin>>B;
			dfs(id,B);
		} else
			cout<<g[id]<<endl;
	}
	return 0;
}
