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
    VI mm(27);
    for(int i=0;i<n;i++)mm[s[i]-'a']++;
    vector<pair<int,char>> m(27);
    for(int i=0;i<26;i++)m[i]={mm[i],i};
    sort(all(m));
    reverse(all(m));
    int mincost=n,mint=n;
    for(int i=1;i<=26;i++){
        if(n%i==0){
            int t=n/i,cost=0,d=0;
            for(int j=0;j<i;j++){
                if(m[j].fi>t)cost+=m[j].fi-t,d+=m[j].fi-t;
                if(m[j].fi<t)d-=t-m[j].fi;
            }cost-=d;
            //cout<<':'<<i<<' '<<cost<<' '<<d<<endl;
            if(cost<mincost)mincost=cost,mint=t;
        }
    }
    cout<<mincost<<endl;
    vector<int> rm(27);
    stack<char> ad;
    set<char> ads;
    for(int j=0;j<n/mint;j++){
        ads.insert('a'+m[j].se);
        if(m[j].fi>mint)rm[m[j].se]=m[j].fi-mint;
        if(m[j].fi<mint){
            for(int i=0;i<mint-m[j].fi;i++)
                ad.push('a'+m[j].se);
        }
    }
    for(int i=0;i<n;i++)if(rm[s[i]-'a'])rm[s[i]-'a']--,s[i]='?';
    for(int i=0;i<n;i++){
        if(!ads.count(s[i])){
            if(ad.size()==0)break;
            s[i]=ad.top();
            ad.pop();
        }
    }
    cout<<s<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}