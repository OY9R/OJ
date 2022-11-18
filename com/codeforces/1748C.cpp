#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
map<int,int> m;
signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		int cntmax=0,sum=0,ans=0;
		bool flag=false;
		m.clear();
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==0){
				if(flag) ans+=cntmax;
				else ans+=m[0];
				flag=1,cntmax=0,m.clear();
			}
			sum+=a[i];
			cntmax=max(cntmax,++m[sum]);
		}
		if(flag) ans+=cntmax;
		else ans+=m[0];
		cout<<ans<<'\n';
	}
	return 0;
}