#include<bits/stdc++.h>
using namespace std;using ll=long long;const ll M2=1e18,P=8,M=1e9+7;const ll inf=1e17;const double eps=1e-10;
struct calcC{//precal needed
	ll poww(ll bs,ll x){ll res=1;for(bs=(bs%M+M)%M;x;x>>=1,(bs*=bs)%=M)if(x&1)(res*=bs)%=M;return res;}
	ll invv(ll bs){return poww(bs,M-2);}}xC;
ll _gcd(ll a,ll b){if(a<b)swap(a,b);while(b)a%=b,swap(a,b);return a;}
ll _lcm(ll a,ll b){return a/_gcd(a,b)*b;}
struct Pri_info{
    int P;vector<int>mind,pris;set<int>priss;
    void ini(int _P){P=_P;mind.resize(P+1,0);//质数/最小质因子
        for(int i=2;i<=P;i++){if(!mind[i])mind[i]=i,pris.push_back(i),priss.insert(i);
            for(auto k:pris){if(k*i>P)break;mind[i*k]=k;if(k==mind[i])break;}}}
}Pfo;
struct S
{
	int n,m,c2=0,c1=0;
	//vector<int>pt;
	ll calc(map<ll,ll>&mp,int pos)
	{
		ll res=0,B=Pfo.pris[pos];
		c1++;
		if(pos==P)
		{
			map<ll,ll>mp3;mp3[1]=1;ll bas=1;
			for(auto k:mp)
			{
				ll x=(xC.poww(2,k.second)-1+M)%M;
				if(k.first==1||(Pfo.priss.count(k.first)&&!mp.count(k.first*B)))
					{(bas*=(k.first*x+1)%M)%=M;continue;}					
				//cout<<k.first<<"*"<<k.second<<'\n';
				map<ll,ll>mp4;
				for(auto&kk:mp3)
				{			
					c2++;
					(mp4[kk.first]+=kk.second)%=M,(mp4[_lcm(kk.first,k.first)]+=ll(kk.second)*x%M)%=M;
				}
				swap(mp3,mp4);
				//for(auto k:mp3)cout<<k.first<<"&"<<k.second<<' ';cout<<'\n';
			}
			//cout<<bas<<'\n';
			//for(auto k:mp3)cout<<k.first<<"&"<<k.second<<' ';cout<<'\n';
			for(auto k:mp3)(res+=k.first*k.second%M)%=M;			
			//cout<<res<<"&"<<bas<<"!!";
			res=res*bas%M;//cout<<res*14<<"###\n";
			return res;
		}
		//pt[pos]=0;
		for(ll i=B,b=1,lst=0;;i*=B)
		{
			map<ll,ll>mp2;
			for(auto&k:mp)if(k.first%i)
			{
				int x=k.first;
				while(x%B==0)x/=B;
				(mp2[x]+=k.second)%=M;c1++;
			}
			ll r2=calc(mp2,pos+1);
			(res+=ll(r2-lst+M)%M*b%M)%=M;lst=r2;
			(b*=B)%=M;//pt[pos]++;
			if(i>n)break;
		}
		//cout<<res<<"!@\n";
		return res;
	}
	void solve()
	{
		clock_t a;
		cin>>n;a=clock();cout<<'('<<P<<")\n";
		map<ll,ll>mp;//pt.resize(200,0);
		for(int i=1;i<=n;i++)mp[i]=1;		
		ll ans=calc(mp,0);cout<<ans<<"&"<<ans%M2<<'\n';
		cout<<c1<<"*"<<c2<<"*\n";
		cout<<"Time:"<<double(clock()-a)<<'\n';
	}
};
void precal(){Pfo.ini(1000);}
int main(){ios::sync_with_stdio(0);cin.tie(0);precal();int t=1;/*cin>>t;*/while(t--) { S SS;SS.solve(); } }