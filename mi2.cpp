#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int &i:a)cin>>i;
    int ans=0;
    for(int i=n-1;~i;i--){
        if(i&&a[i]>=a[i-1])a[i-1]+=a[i];
        ans=max(ans,a[i]);
    }
    cout<<ans<<endl;
}