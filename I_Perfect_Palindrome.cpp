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
string s;
void solve(){
	cin >> s;
    int size = s.size();
    vector<int> a(26);
    for(int i=0;i<size;i++) 
        a[s[i]-'a'] ++;
    
    int ans = 0;
    for(int i= 0;i<size;i++){
            ans=max(ans,a[s[i]-'a']);
    }
    cout << size - ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}