#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m=0,ans=0;cin>>n;
    vector<int> a(n),lmax(n),rmax(n);
    for(int i=0;i<n;i++)cin>>a[i];
    lmax[0]=a[0]; rmax[n-1]=a[n-1];
    for(int i=1;i<n;i++)lmax[i]=max(lmax[i-1],a[i]);
    for(int i=n-2;i>=0;i--)rmax[i]=max(rmax[i+1],a[i]);
    for(int i=0;i<n;i++)ans+=max(0,min(lmax[i],rmax[i])-a[i]);
    cout<<ans<<endl;
}