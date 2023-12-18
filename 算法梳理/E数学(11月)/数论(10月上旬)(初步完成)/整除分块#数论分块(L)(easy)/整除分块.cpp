#include<bits/stdc++.h>//整除分块 ttf:https://codeforces.com/contest/1780/problem/E
using namespace std;using ll=long long;const int M=998244353;const ll inf=1e17;const double eps=1e-10;
struct DDB//i:[1,bord] n/i:[1,segc]
{//floor(L/k)<=i -> L<(i+1)*k -> k>floor(L/(i+1)) -> k>=floor(L/(i+1)+1
	int n,bord,segc=0;vector<pair<int,int>>segs;//[a,b]闭区间
	DDB(int _n){ini(_n);}void ini(int _n){//n:[0,int)
		n=_n;bord=n;segs.emplace_back(0,0);
		for(int i=1,nL;i*i<=n;i++){nL=n/(i+1)+1;//floor(n/k)==i
			segs.emplace_back(nL,bord);segc++;bord=nL-1;}}};
struct S{//https://codeforces.com/contest/1780/submission/235396437
	void solve(){ll L,R;cin>>L>>R;L--;ll ans=max(0ll,R/2-L);DDB db(L);
		for(int i=1;i<=db.bord;i++)ans+=bool(R/i-1>L/i);
		for(int i=1;i<=db.segc;i++){ll nL=db.segs[i].first,nR=db.segs[i].second+1,
			sL=R/(i+2)+1;ans+=max(min(nR,sL)-nL,0ll);}cout<<ans<<"\n";}};
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;cin>>t;while(t--){S SS;SS.solve();}}