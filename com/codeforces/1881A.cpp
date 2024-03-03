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
	int n,m;cin>>n>>m;
    string s1,s2;cin>>s1>>s2;
    int cnt=0;
    while(s1.size()<s2.size())s1=s1+s1,cnt++;
    if(s1.find(s2)==s1.npos){
        s1=s1+s1,cnt++;
        if(s1.find(s2)==s1.npos){
            cout<<-1<<endl;
            return;
        }else{
            cout<<cnt<<endl;
            return;
        }
    }
    cout<<cnt<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}