#include<bits/stdc++.h>
using namespace std;
constexpr int N=44;
int n,res=INT_MAX;
int s[N];
vector<pair<int,int>> v[N];
void dfs(int u,int sum,int cnt){
    if(cnt>n)res=min(res,sum);
    if(cnt>n||s[1]||sum+n-cnt+1>res)return;
    for (auto it : v[u])
        if (!s[it.first]){
            s[it.first]=1;
            dfs(it.first,sum + it.second,cnt + 1);
            s[it.first]=0;
        }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++ i)
        for (int j=1,w;j<=n;++ j){
            cin>>w;
            v[i].push_back({j,w});
        }
    dfs(1,0,1);
    cout<<res;
    return 0;
}