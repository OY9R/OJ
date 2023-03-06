#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int n;cin>>n;cout<<ans<<'\n'){
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        ans=1;
        for(int i=0;i<n;i++)
            ans=ans*(a[i]-i)%mod;
    }
}