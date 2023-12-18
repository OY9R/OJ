#include<iostream>//形状固定杨氏矩阵计数 test;http://poj.org/problem?id=1825
#include<vector>
using namespace std;
typedef long long ll;
int n,siz;
vector<int>pris,cc;
struct Pris{vector<int>mind;
    void precal(int P){mind.resize(P+1,0);for(int i=2;i<=P;i++)
        {if(!mind[i])mind[i]=i,pris.push_back(i);for(int i=0,k;i<int(pris.size());i++)
            {k=pris[i];if(k*i>P)break;mind[k*i]=k;if(mind[i]==k)break;}}}}Pri;
struct S
{
	void divi(int x,int v){for(int i=0;i<siz;i++)while(x%pris[i]==0)x/=pris[i],cc[i]+=v;}
	void solve()
	{
		int n,sum=0;cin>>n;vector<int>a(n+1),cnt(32,0);
		for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
		for(int j=1,pt=n;j<=a[1];j++)
		{
			while(a[pt]<j)pt--;
			for(int i=1;i<=pt;i++)cnt[pt-i+a[i]-j+1]++;
		}
		for(int i=1;i<=sum;i++)divi(i,1);
		for(int i=1;i<=31;i++)divi(i,-cnt[i]);
		//for(int i=1;i<=10;i++)cout<<i<<"*"<<cnt[i]<<'\n';
		//for(int i=0;i<siz;i++)cout<<pris[i]<<"*"<<cc[i]<<'\n';
		vector<int>rr(1000,0);int pt=1;rr[1]=1;
		for(int i=0;i<siz;i++)while(cc[i]--)
		{
			for(int j=1;j<=pt;j++)rr[j]*=pris[i];
			for(int j=1;j<=pt;j++)
			{
				rr[j+1]+=rr[j]/10;rr[j]%=10;if(j==pt&&rr[j+1])pt++;
			}
		}
		for(int j=pt;j;j--)cout<<rr[j];cout<<'\n';
	}
};
int main()
{
	//freopen("1.in","r",stdin);
	//cout<<fixed<<setprecision(12);
	ios::sync_with_stdio(0);cin.tie(0);
	Pri.precal(240);siz=pris.size();cc.resize(siz);
	int t=1;/*cin>>t;*/
	while(t--){S SS;SS.solve();}
}