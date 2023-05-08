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
    int n,m,a,b,c;cin>>n>>m;
    cout<<"? 1 1\n"<<flush,cin>>a;
    if(a>=n){
        cout<<"? 1 "<<a+1<<endl<<flush,cin>>b;
        cout<<"! "<<b+1<<' '<<a+1<<endl<<flush;
    }else if(a>=m){
        cout<<"? "<<a+1<<" 1\n"<<flush,cin>>c;
        cout<<"! "<<a+1<<' '<<c+1<<endl<<flush;
    }else{
        cout<<"? 1 "<<a+1<<endl<<flush,cin>>b;
        cout<<"? "<<a+1<<" 1\n"<<flush,cin>>c;
        if(a==b&&b==c)cout<<"! "<<a+1<<' '<<a+1<<endl<<flush;
        else if(b==a)cout<<"! "<<a+1<<' '<<c+1<<endl<<flush;
        else cout<<"! "<<b+1<<' '<<a+1<<endl<<flush;
    }
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}