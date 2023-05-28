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
    int l=-1;
    char c='0';
    for(int i=0;i<s.size();i++){
        if(s[i]!='?'){
            for(int j=l+1;j<i;j++)s[j]=s[i];
            l=i;c=s[i];
        }
    }
    for(int i=s.size()-1;i>=0&&s[i]=='?';i--){
        s[i]=c;
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