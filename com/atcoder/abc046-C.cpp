#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    vector<long long> t(n),a(n);
    for(int i=0;i<n;i++)cin>>t[i]>>a[i];
    long long tt=1,aa=1;
    for(int i=0;i<n;i++){
        long long tm,am,m;
        tm=(tt-1)/t[i]+1;
        am=(aa-1)/a[i]+1;
        m=max(tm,am);
        tt=t[i]*m;
        aa=a[i]*m;
    }
    cout<<tt+aa;
}
