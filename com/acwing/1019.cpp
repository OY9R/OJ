#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+2);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        vector<int> dp(n+2);
        a[0]=0,a[n+1]=0;
        int res=0;
        dp[0]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
                if(a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+1);
        for(int i=1;i<=n;i++){      
            res=max(res,dp[i]);
            dp[i]=0;
        }
        dp[n+1]=0;
        for(int i=n;i;i--)
            for(int j=n+1;j>i;j--)
                if(a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+1);
        for(int i=1;i<=n;i++)      
            res=max(res,dp[i]);
        cout<<res<<endl;
    }
    return 0;
}