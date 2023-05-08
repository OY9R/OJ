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
    int n;cin>>n;
    string s;cin>>s;
    if(n%2){cout<<-1<<endl;return;}
    vector<int> cnt(26);
    for(int i=0;i<n;i++)cnt[s[i]-'a']++;
    for(int i=0;i<26;i++)if(cnt[i]*2>n){cout<<-1<<endl;return;}
    vector<int> pair(26);
    int pairs=0;
    for(int i=0;i*2<n;i++)if(s[i]==s[n-i-1])pairs++,pair[s[i]-'a']++;
    for(int i=0;i<26;i++)if(pair[i]*2>pairs){cout<<pair[i]<<endl;return;}
    cout<<(pairs+1)/2<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}