//ÇóÔ­¸ù
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int M = 998244353;
vector<int>pris, mind;
void getpri(int siz)
{
    mind.resize(siz + 1, 0);
    for (int i = 2; i <= siz; i++)
    {
        if(!mind[i])mind[i]=i,pris.push_back(i);
        for (auto k : pris)
        {
            if(k*mind[i]>siz)break;
            mind[k*mind[i]]=mind[i];
            if(k==mind[i])break;
        }
    }
}
ll poww(ll bs,ll x,int m){ll ans=1;for(;x;x>>=1,(bs*=bs)%=m)if(x&1)(ans*=bs)%=m;return ans;}
ll invv(ll bs,int m){return poww(bs,m-2,m);}
int getroot(int x)
{
    vector<int>pf;int x2=x;x--;//pri:x-1|else phi(x)
    for(auto k:pris)
    {
        if(k*k>x)break;if(x%k)continue;
        pf.push_back(k);while(x%k==0)x/=k;
    }
    if(x!=1)pf.push_back(x);
    for(int i=2;i<=10;i++)
    {
        bool jud=0;
        for(auto k:pf)if(poww(i,(x2-1)/k,x2)==1){jud=1;break;}
        if(!jud)return i;
    }
    return 0;
}
int main()
{
    getpri(32000);int x;cin>>x;
    cout<<getroot(x);
}