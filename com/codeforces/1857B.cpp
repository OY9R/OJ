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
	string s;cin>>s;
    int n=s.size();
    int jw=0,jwi=n;
    per(i,0,n){
        s[i]+=jw;
        if(s[i]>='5'){
            s[i]='0';
            jw=1;
            jwi=i;
        }else{
            jw=0;
        }
    }
    if(jw==1){
        cout<<1;
        rep(i,0,n)cout<<0;
    }else{
        rep(i,0,jwi)cout<<s[i];
        rep(i,jwi,n)cout<<0;
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