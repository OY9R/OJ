//exKMP:test:https://www.luogu.com.cn/problem/P5410
#include<bits/stdc++.h>
using namespace std;using ll=long long;
struct exKMP{//bas:1 in/1 out
	vector<int>Z,ext;string sa,sb;int la,lb;
	void solve(){//Z:(b[1]&b[i])lcs length//ext:(b[1]&a[i])lcs length
		cin>>sa>>sb;la=sa.length();lb=sb.length();sa="%"+sa+"#";sb="$"+sb+"@";
		Z.resize(lb+1,0);for(int i=2,L,R=-1;i<=lb;i++){if(R>=i)Z[i]=min(Z[i-L+1],R-i+1);
			while(sb[i+Z[i]]==sb[Z[i]+1])Z[i]++;if(i+Z[i]-1>R)L=i,R=i+Z[i]-1;}Z[1]=lb;
		ext.resize(la+1,0);for(int i=1,L,R=-1;i<=la;i++){if(R>=i)ext[i]=min(Z[i-L+1],R-i+1);
			while(sa[i+ext[i]]==sb[ext[i]+1])ext[i]++;if(i+ext[i]-1>R)L=i,R=i+ext[i]-1;}}};
int main(){ios::sync_with_stdio(0);cin.tie(0);exKMP SS;SS.solve();}