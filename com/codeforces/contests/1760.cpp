#include<bits/stdc++.h>
using namespace std;
long long f(vector<int> a) {
    long long sum=0,tmp=0;
    for(int i=0;i<a.size();i++){
        if(a[i])tmp++;
        else sum+=tmp;
    }
    return sum;
}
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        long long ans=0;
        int l=0,r=n-1;
        while(l<n&&a[l])l++;
        while(r>=0&&!a[r])r--;
        a[l]=1;
        ans=max(ans,f(a));
        a[l]=0;
        a[r]=0;
        ans=max(ans,f(a));
        a[r]=1;
        cout<<ans<<'\n';
    }
    return 0;
}