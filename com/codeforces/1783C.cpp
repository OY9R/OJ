#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,m,ans=-1;cin>>n>>m;
    vector<PII > a(n);
    vector<int> b(n);
    vector<bool> st(n);
    for(int i=0;i<n;i++)cin>>a[i].first;
    for(int i=0;i<n;i++)b[i]=a[i].first;
    for(int i=0;i<n;i++)a[i].second=i;
    sort(all(a));
    int maxv=0;
    for(int i=0;i<n;i++){
        if(m>=a[i].first){
            ans++;
            m-=a[i].first;
            maxv=max(maxv,a[i].first);
            st[a[i].second]=1;
        }
    }   
    if(ans!=n-1)
        if(st[ans+1])ans++;
        else if(m+maxv-b[ans+1]>=0)ans++;
    cout<<n-ans<<endl;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}