//KMP:test:https://www.luogu.com.cn/problem/P3375
#include<bits/stdc++.h>
using namespace std;using ll=long long;
struct KMP{//1 bas
	vector<int>nxt,fit;string sa,sb;int la,lb;
	void solve(){//mr:rmost reached/lres:last cnt
		cin>>sa>>sb;la=sa.length();lb=sb.length();nxt.resize(lb+1);nxt[0]=-1;nxt[1]=0;
		for(int i=2,x;i<=lb;nxt[i++]=nxt[x]+1)for(x=i-1;x&&sb[nxt[x]]!=sb[i-1];x=nxt[x]);nxt[0]=0;
		for(int L=1,R=lb,mr=0,lc=1;R<=la;mr=max(mr,L++),R++)if(nxt[lc]>mr-L)
			{while(mr<R&&sa[mr+1-1]==sb[mr-L+1])mr++;lc=mr-L+1;if(lc==lb)fit.push_back(L);}
		for(auto k:fit)cout<<k<<'\n';for(int i=1;i<=lb;i++)cout<<nxt[i]<<' ';}};
int main(){ios::sync_with_stdio(0);cin.tie(0);KMP SS;SS.solve();}