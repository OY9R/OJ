#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main() {
    int n,t;cin>>n>>t; // t?
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    b[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)b[i]=max(b[i+1],a[i]);
    int mx=0,ans=0;
    for(int i=0;i<n;i++){
        if(b[i]-a[i]>mx)mx=b[i]-a[i],ans=1;
        else if(b[i]-a[i]==mx)ans++;
    }
    cout<<ans;
    return 0;
}