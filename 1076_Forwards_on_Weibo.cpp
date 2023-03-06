#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int> > g;
set<int> s;
int st[1001];
void dfs(int u,int d){
    s.insert(u);
    st[u]=d+1;
    if(d==0)return;
    for(int i: g[u])
        if(st[i]<d)
            dfs(i,d-1);
}
int main(){
	cin>>n>>k;
    g=vector<vector<int> >(n+1);
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        while(t--){
            int f;cin>>f;
            g[f].push_back(i);
        }
    }
    int q;cin>>q;
    while(q--){
        s.clear();
        memset(st,0,sizeof st);
        int t;cin>>t;
        dfs(t,k);
        cout<<s.size()-1<<endl;
    }
}