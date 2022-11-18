#include<bits/stdc++.h>
using namespace std;
const int N = 200200;
int a[N],b[N];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    int l=1,ans=0;
    for(int i=2;i<=n;i++)
        if(a[i-1]!=a[i]&&a[i-1]+1!=a[i]){
            ans=max(ans,b[i-1]-b[l-1]),l=i;
            cout<<ans<<' ';
        }
    if((a[n]+1)%m==a[1]){
        a[0]=-1;
        for(int i=1;i<=n;i++)
            if(a[i-1]!=a[i]&&a[i-1]+1!=a[i]){
                ans+=b[i-1];
                break;
            }
    }
    cout<<ans;
    return 0;
}