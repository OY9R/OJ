#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=998244353;const double eps=1e-10,inf=1e30;
bool chk(int L,int segc)
{
	if(L%segc)return 0;int B=L/segc;
	for(int j=1;j<segc;j++)if(s.substr(0,B)!=s.substr(B*j,B))return 0;return 1;
}
void solve()
{
	cin>>s;int n=s.length(),lft=n,segc=1;
	for(int i=2;i*i<=lft;i++)if(lft%i==0)
	{
		int L=n;while(chk(L,i))L/=i,segc*=i;
		while(lft%i==0)lft/=i;
	}
	if(chk(n,lft))segc*=lft;cout<<n/segc<<'\n';
}