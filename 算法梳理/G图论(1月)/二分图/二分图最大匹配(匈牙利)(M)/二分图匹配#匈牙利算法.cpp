#include<bits/stdc++.h>//二分图匹配/匈牙利算法
using namespace std;
struct Hungarian{//1-n match 1-m
    int n,m,tc=0;vector<vector<int>>es;vector<int>tim,match_id;
    inline bool trial(int x){for(auto k:es[x])if(tim[k]!=tc){tim[k]=tc;
        if(!match_id[k]||trial(match_id[k])){match_id[k]=x;return 1;}}return 0;}
    void ini(int _n,int _m){n=_n++,m=_m++;es.resize(_n);tim.resize(_m,0);match_id.resize(_m,0);}
    inline int match(int n){int res=0;for(int i=1;i<=n;i++)tc++,res+=trial(i);return res;}}Hun;
int main(){int n,m,e;cin>>n>>m>>e;Hun.ini(n,m);for(int i=1,x,y;i<=e;i++)
    cin>>x>>y,Hun.es[x].push_back(y);cout<<Hun.match(n)<<'\n';}