#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
bool say(bool ans){
    cout<<(ans?"YES\n":"NO\n");
    return ans;
}
void solve(){
    int n,ans=0;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)
        if(a[i]<b[i]){ans=-1;break;}
    int m;cin>>m;
    map<ll,int> mm;
    for(int i=0;i<m;i++){
        int c;cin>>c;
        if(mm.count(c))mm[c]++;
        else mm[c]=1;
    }
    if(ans==-1){say(false);return;}
    stack<ll> s;
    for(int i=0;i<n;i++){
        while(s.size()&&b[i]>s.top())s.pop();
        if(s.size()){
            if(a[i]>b[i]&&s.top()>b[i]){
                if(mm.count(b[i])==0||mm[b[i]]==0){say(false);return;}
                mm[b[i]]--;
                s.push(b[i]);
            }
        }else{
            if(a[i]>b[i]){
                if(mm.count(b[i])==0||mm[b[i]]==0){say(false);return;}
                mm[b[i]]--;
                s.push(b[i]);
            }
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;){
    //         if(a[j]!=b[j]&&b[j]==c[i]){
    //             while(b[j]<=c[i]&&j<n)
    //                 a[j]=min(a[j],c[i]),j++;
    //             break;
    //         }else j++;
    //     }
    // }
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<' ';
    // for(int i=0;i<n;i++)
    //     if(a[i]!=b[i]){say(false);return;}
    say(true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}