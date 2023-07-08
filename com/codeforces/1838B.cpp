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
    VI a(n);
    rep(i,0,n)cin>>a[i];
    int i1,i2,in;
    rep(i,0,n){
        if(a[i]==1)i1=i;
        if(a[i]==2)i2=i;
        if(a[i]==n)in=i;
    }
    if(i1>i2)swap(i1,i2);
    // cout<<i1<<' '<<n-i2-1<<' ';
    if(in<i1||in>i2){
        if(in<i1){
            cout<<1<<' '<<i1+1;
        }else{
            cout<<i2+1<<' '<<n;
        }
    }else if(i1>n-i2-1){
        cout<<1<<' '<<i1+1;
    }else{
        cout<<i2+1<<' '<<n;
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