#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    vector<int> a(26),b(26,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(s[i]-'a'==j)b[j]=max(a[j],b[j]),a[j]=0;
            else a[j]++;
        }
    }
    for(int i=0;i<26;i++)b[i]=max(a[i],b[i]);
    int minn=INT_MAX;
    for(int i=0;i<26;i++){
        if(b[i]!=-1)minn=min(minn,b[i]);
    }
    // for(int i=0;i<26;i++)cout<<b[i]<<" \n"[i==25];
    while(minn)minn>>=1,ans++;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}