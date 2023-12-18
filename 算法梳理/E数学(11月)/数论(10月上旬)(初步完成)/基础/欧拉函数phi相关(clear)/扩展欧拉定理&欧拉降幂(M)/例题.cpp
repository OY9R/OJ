//扩展欧拉定理&欧拉降幂(M) 求(x-t+1)^x(%(k^2))
//https://ac.nowcoder.com/acm/contest/66443/C
#include<bits/stdc++.h>
typedef long long ll;using namespace std;vector<int>pris,mind;
ll poww(ll bs,ll x,ll m) { ll res=1;for(;x;x>>=1,(bs*=bs)%=m)if(x&1)(res*=bs)%=m;return res; }
void getpri(int siz){mind.resize(siz+1,0);
    for(int i=2; i<=siz; i++){if(!mind[i])mind[i]=i,pris.push_back(i);
        for(auto k:pris){if(k*mind[i]>siz)break;
            mind[k*mind[i]]=mind[i];if(k==mind[i])break;}}}
ll getphi(ll x){ll phi=x;for(auto k:pris){if(k*k>x)break;
    if(x%k==0)phi=phi/k*(k-1);while(x%k==0)x/=k;}
    if(x!=1)phi=phi/x*(x-1);return phi;}
ll mods(string &s,ll mod){ll bs=0;for(auto k:s)bs=(bs*10+(k-'0'))%mod;return bs;}
void solve(){
    string x;ll k,t;cin>>x>>k;t=mods(x,k);k*=k;
    ll midc1=(mods(x,k)-t+1+k)%k,kphi=getphi(k),midc2=mods(x,kphi)+kphi;
    cout<<poww(midc1,midc2,k)<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0);getpri(1e6+20);solve();}