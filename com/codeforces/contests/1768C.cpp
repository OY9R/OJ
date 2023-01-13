#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,ans=0;cin>>n;
    vector<PII> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    set<int> b,c;
    VI bb,cc;
    int mb=1,mc=1;
    for(int i=0;i<n;i++){
        if(b.count(a[i].first)==0){
            b.insert(a[i].first);
            bb.push_back(a[i].first);
            while(mc<=a[i].first&&c.count(mc))mc++;
            if(mc>a[i].first){cout<<"NO\n";return;}
            c.insert(mc);
            cc.push_back(mc);
        }else if(c.count(a[i].first)==0){
            c.insert(a[i].first);
            cc.push_back(a[i].first);
            while(mb<=a[i].first&&b.count(mb))mb++;
            if(mb>a[i].first){cout<<"NO\n";return;}
            b.insert(mb);
            bb.push_back(mb);
        }else{cout<<"NO\n";return;}
    }
    cout<<"YES\n";
    VI dd(n);
    for(int i=0;i<n;i++)
        dd[a[i].second]=cc[i];
    for(int i=0;i<n;i++)
        cout<<dd[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)
        dd[a[i].second]=bb[i];
    for(int i=0;i<n;i++)
        cout<<dd[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}