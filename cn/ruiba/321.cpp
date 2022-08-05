#include <bits/stdc++.h>
using namespace std;
const int N=2e2+10;
int n,m,k,mn=INT_MAX,res;
int s[N],w[N];
void dfs(int u,int sum){
    if(abs(sum-m)<mn){
        mn=abs(sum-m);
        res=sum;
    }
    if (u>n||sum-m>=mn||sum+s[n]-s[u-1]<m-mn)return;
    dfs(u+1,sum+w[u]);
    dfs(u+1,sum);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i],s[i]=s[i-1]+w[i];
    dfs(1,0);
    return cout<<res,0;
}