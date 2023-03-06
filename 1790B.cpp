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
    int a,b,c;cin>>a>>b>>c;
    int t=b-c;
    cout<<b-c<<' ';
    c-=a-1;
    for(int i=1;i<a;i++){
        c-=t-1;
        if(c>=0)cout<<t<<' ';
        else{
            cout<<t+c<<' ';
            while(++i<a){
                cout<<1<<' ';
            }
        }
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}