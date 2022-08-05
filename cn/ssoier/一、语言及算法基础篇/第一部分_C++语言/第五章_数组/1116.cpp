#include<bits/stdc++.h>
using namespace std;
int main(){//error
    int n,a[105],dp[105],mx=0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=a[i]==a[i-1]?dp[i-1]+1:1;
        mx=max(mx,dp[i]);
    }
    cout<<mx;
    return 0;
}