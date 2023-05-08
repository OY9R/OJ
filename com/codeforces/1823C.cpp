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
    map<int,int> mp;
    int n;cin>>n;
    rep(i,0,n){
        int tmp;cin>>tmp;
        for(int j=2;j*j<=tmp;j++){
            while(tmp%j==0){
                mp[j]++;
                tmp/=j;
            }
        }
        if(tmp!=1)mp[tmp]++;
    }
    int sum1=0,sum2=0;
    for(auto q:mp){
        sum1+=q.second/2;
        sum2+=q.second%2;
    }
    cout<<sum1+sum2/3<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}