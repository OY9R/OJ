#include<bits/stdc++.h>//取质因子
using namespace std;typedef long long ll;
const int N=2e5+10;vector<int>pris,mind;
void getpri(int siz){mind.resize(siz+1,0);
    for(int i=2; i<=siz; i++)
    {if(!mind[i])mind[i]=i,pris.push_back(i);
        for(auto k:pris){if(k*mind[i]>siz)break;
        mind[k*mind[i]]=mind[i];if(k==mind[i])break;}}}
void getprifac(vector<int>&v,int x){
    for(auto k:pris){if(k*k>x)break;if(x%k)continue;
        v.push_back(k);while(x%k==0)x/=k;}if(x!=1)v.push_back(x);}
void solve(){int x;cin>>x;vector<int>v;getprifac(v,x);
    for(auto k:v)cout<<k<<' ';cout<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0); getpri(32000);solve();}