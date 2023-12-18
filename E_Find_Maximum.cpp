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
int f(int x){
    if(x==0)return 1;
    if(x%3)return f(x-1)+1;
    else return f(x/3)+1;
}
void bao(){
    for(int i=0;i<1000;i++){
        int l=rand()%1000000;
        int r=l+rand()%1000;
        int ansb=0;
        int mansb;
        for(int i=l;i<=r;i++){
            int tmp = f(i);
            if(tmp>ansb)ansb=tmp,mansb=i;
        }
        int bl=l,br=r;
        ll ans=0,mans=0,ans2=0;
        vector<int> L,R;
        while(l)L.pb(l%3),l/=3;
        while(r)R.pb(r%3),ans2+=r%3+1,r/=3;
        L.resize(max(L.size(),R.size()));
        R.resize(max(L.size(),R.size()));
        bool flag=1,flag2=1;
        int n=L.size();
        per(i,0,n){
            if(L[i])flag=0;
            if(L[i]==R[i]&&flag2)ans+=R[i]+1;
            else{
                ans+=R[i]+1;
                mans=max(mans,ans+i*3-1-(flag&&R[i]==1));
                flag2=0;
            }
        }
        if(max(ans,mans)!=ansb){
            cout<<bl<<' '<<br<<' '<<ans<<' '<<mans<<' '<<ansb<<' '<<mansb<<endl;
        }
    }
}
void solve(){
    ll l,r,ans=0,mans=0,ans2=0;cin>>l>>r;
    vector<int> L,R;
    while(l)L.pb(l%3),l/=3;
    while(r)R.pb(r%3),ans2+=r%3+1,r/=3;
    L.resize(max(L.size(),R.size()));
    R.resize(max(L.size(),R.size()));
    bool flag=1,flag2=1;
    int n=L.size();
    per(i,0,n){
        if(L[i])flag=0;
        if(L[i]==R[i]&&flag2)ans+=R[i]+1;
        else{
            ans+=R[i]+1;
            mans=max(mans,ans+i*3-1-(flag&&R[i]==1));
            flag2=0;
        }
    }
    cout<<max(ans,mans)<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
    while(n--)solve();
    // bao();
	return 0;
}