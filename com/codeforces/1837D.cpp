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
    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')l++;
        else r++;
    }
    // cout<<l<<' '<<r<<endl;
    if(l!=r){cout<<-1<<endl;return;}
    int cnt=0,ans=1,flag=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') cnt++;
        else cnt--;
        if(flag==0||cnt*flag<0){
            flag=cnt;
            ans++;
        }

    }
    if(ans>2)cout<<2<<endl;
    else cout<<1<<endl;
    cnt=0,ans=1,flag=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') cnt++;
        else cnt--;
        if(flag==0||cnt*flag<0){
            flag=cnt;
            ans++;
        }
        cout<<ans%2+1<<' ';
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