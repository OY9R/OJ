//AC自动机 找出哪些模式串在文本串中出现的次数最多
//blog:https://www.cnblogs.com/cjyyb/p/7196308.html
//test:https://www.luogu.com.cn/problem/P3796
//qualified https://codeforces.com/gym/104725/problem/H
#include<bits/stdc++.h>
using namespace std;
struct ACam{
	struct ACnode{bool lit=0;int nxt=0,tran=0,cnt=0;vector<int>chd;ACnode(){chd.resize(26,0);}};
	int n,tot=0;vector<string>s;vector<ACnode>nod;
	void ini(int _n,int sl){n=_n;s.resize(n);nod.resize(sl);}/*sl:sumlen*/
	void Trie_Fail_pre(){//O(26*sumlen)
		for(int i=0,x;i<n;i++){cin>>s[i];x=0;for(auto k:s[i]){int c=k-'a';
		if(!nod[x].chd[c])nod[x].chd[c]=++tot;x=nod[x].chd[c];}nod[x].lit=1;nod[x].tran=i;}
		queue<int>Q;Q.push(0);for(;!Q.empty();Q.pop())for(int i=0,p=Q.front(),x;i<26;i++)
			{int des=nod[p].chd[i];if(!des)continue;Q.push(des);if(!p)continue;
				for(x=nod[p].nxt;!nod[x].chd[i]&&x;x=nod[x].nxt);nod[des].nxt=nod[x].chd[i];}}
	void Newstring_Analyze(){//O(len*(1+mxlen))//1:fail->dep_drop
		string ss;cin>>ss;int x=0;for(auto k:ss){
			int c=k-'a';while(!nod[x].chd[c]&&x)x=nod[x].nxt;x=nod[x].chd[c];
			for(int p=x;p;p=nod[p].nxt)if(nod[p].lit)nod[p].cnt++;}}
	void Calc(){int mx=0;for(int i=1;i<=tot;i++)if(nod[i].cnt>mx)mx=nod[i].cnt;
		cout<<mx<<'\n';for(int i=1;i<=tot;i++)if(nod[i].cnt==mx)cout<<s[nod[i].tran]<<'\n';}
	void Solve(){Trie_Fail_pre();Newstring_Analyze();Calc();}
};
void solve(int n){ACam S;S.ini(n,11000);S.Solve();}
int main(){ios::sync_with_stdio(0);cin.tie(0);while(1){int n;cin>>n;if(!n)break;solve(n);}}