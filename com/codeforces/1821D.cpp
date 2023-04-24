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
const int INF=0x3f3f3f3f,mod=1e9+7,N=200020;
int L[N],R[N],S[N];
int dp[N][2];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>L[i];
    for(int i=0;i<n;i++)cin>>R[i];
    for(int i=0;i<n;i++)S[i]=R[i]-L[i]+1;
    priority_queue<int,vector<int>, greater<int>> q;
    int sum=0,ans=INT_MAX;
    for(int i=0;i<n;i++){
        // cout<<' '<<S[i]<<':';
        q.push(S[i]);
        m-=S[i];
        if(m<=0){
            ans=min(ans,(int)q.size()*2+R[i]+m);
            // cout<<q.size()<<'+'<<R[i]+m;
            while(m<=0){
                m+=q.top();
                q.pop();
                if(m<=0){
                    ans=min(ans,(int)q.size()*2+R[i]+m);
                    // cout<<','<<q.size()<<'+'<<R[i]+m;
                }
            }
        }
        // cout<<' ';
    }
    // cout<<'=';
    cout<<(ans==INT_MAX?-1:ans)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}