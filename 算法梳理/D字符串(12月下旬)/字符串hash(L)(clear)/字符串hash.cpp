//×Ö·û´®hash test:https://www.luogu.com.cn/problem/P3370
#include<bits/stdc++.h>
using namespace std;using ll=long long;
struct String_Hash{//precal Maxlen needed
    int p[2]={998244353,100000007},g[2]={68,70},N;vector<pair<int,int>>bs;
    void precal(int _n){N=_n;bs.resize(N+1);bs[0]={1,1};for(int i=1;i<=N;i++)
        bs[i]={ll(bs[i-1].first)*g[0]%p[0],ll(bs[i-1].second)*g[1]%p[1]};}
    int tran(char c){if(c>='a')return c-'a'+27;if(c>='A')return c-'A'+11;return c-'0'+1;}
    vector<pair<int,int>>Prehash(string& s){
        int len=s.length();vector<pair<int,int>>res(len+1);res[0]={1,1};
        for(int i=1;i<=len;i++)res[i]={(ll(res[i-1].first)*g[0]+tran(s[i-1]))%p[0],
            (ll(res[i-1].second)*g[1]+tran(s[i-1]))%p[1]};return res;}
    pair<int,int> Calhash(vector<pair<int,int>>&v,int l,int r){//if 0bas l++/r++
        l++,r++;return{(v[r].first-ll(v[l-1].first)*bs[r-l+1].first%p[0]+p[0])%p[0],
            (v[r].second-ll(v[l-1].second)*bs[r-l+1].second%p[1]+p[1])%p[1]};}
}S_hash;
struct satsky{void Solve(){int n;string s;set<pair<int,int>>xSet;cin>>n;while(n--)
    {cin>>s;auto Hs=S_hash.Prehash(s);xSet.insert
    (S_hash.Calhash(Hs,0,s.length()-1));}cout<<xSet.size()<<'\n';}};
int main(){ios::sync_with_stdio(0);cin.tie(0);S_hash.precal(1e6+5);
    int t=1;/*cin>>t;*/while(t--){satsky S;S.Solve();}}