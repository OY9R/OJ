#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll sum=0,ans=0;
    int j=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        for(;j<=i&&a[j]<=sum/(i+1);j++);
        ans=max(ans,(ll)i-j+1);
    }
    cout<<ans<<endl;
	return 0;
}