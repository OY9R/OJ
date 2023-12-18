//(ex)BSGS source:https://www.cnblogs.com/cjoieryl/p/8748022.html
//test:https://www.luogu.com.cn/problem/P4195
#include<bits/stdc++.h>
using namespace std;using ll=long long;
int _gcd(int a,int b){if(a<b)swap(a,b);while(b)a%=b,swap(a,b);return a;}
struct exBSGS{//ex:gcd(a,p)!=1//(a^(x-xd))*bas=b(%p),get x(>=0)|||b1*(a^P)^c1=b2*a^c2(c1,c2:1-P)
	int solve(int a,int b,int p){//No solution:-1//else minimal
		if(!p)exit(0);a%=p,b%=p;if(p==1)return 0;
		if(!a){if(!b)return 1;if(b==1)return 0;return -1;}
		int xd=0,bas=1;while(1){if(bas==b)return xd;int g=_gcd(a,p);
			if(g==1)break;if(b%g)return -1;xd++;p/=g,b/=g,bas=ll(bas)*(a/g)%p;}
		int res=p;int amP=1;int P=sqrt(p)+5;map<int,int>mp;
		for(int i=1,val=ll(b)*a%p;i<=P;i++,val=ll(val)*a%p)mp[val]=i,amP=ll(amP)*a%p;
		for(int i=1,val=ll(bas)*amP%p;i<=P;i++,val=ll(val)*amP%p)if(mp.count(val))res=min(res,P*i-mp[val]);
		if(res==p)return -1;return res+xd;}}exB;
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;
	while(1){int a,p,b;cin>>a>>p>>b;int val=exB.solve(a,b,p);
		(val==-1)?cout<<"No Solution\n":cout<<val<<'\n';}}