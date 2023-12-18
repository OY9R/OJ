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
	int n,x=0,y=0;cin>>n;
    string s;cin>>s;
    set<PII>st;st.insert({0,0});
    for(char c:s){
        switch(c){
            case 'R':x++;break;
            case 'L':x--;break;
            case 'U':y++;break;
            case 'D':y--;break;
        }
        st.insert({x,y});
    }
    if(st.size()==n+1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}