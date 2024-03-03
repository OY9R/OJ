#include<bits/stdc++.h>
using namespace std;
int n,r,a[22];
void dfs(int t){
    if(t>r)for(int i=1;i<=r+1;printf(i<r+1?"%3d":"\n",a[i++]));
    else for(a[t]=a[t-1]+1;a[t]<=n;dfs(t+1),a[t]++);
}
int main(){
    cin>>n>>r;
    dfs(1);
}
