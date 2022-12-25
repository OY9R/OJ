#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    long long n,x;cin>>n>>x;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    long long ans=0;
    for(int i=1;i<n;i++){
        if(a[i]+a[i-1]>x){
            ans+=a[i]+a[i-1]-x;
            a[i]-=a[i]+a[i-1]-x;
            if(a[i]<0){
                a[i-1]-=a[i];
                a[i]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}