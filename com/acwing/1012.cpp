#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> m(n+1);
    m[0]={0,0};
    for(int i=1;i<=n;i++)
        cin>>m[i].first>>m[i].second;
    sort(m.begin(),m.end());
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(m[i].second>m[j].second)dp[i]=max(dp[i],dp[j]+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}