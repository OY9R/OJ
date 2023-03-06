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
int a[50005][15];
string tostr(VI in){
    string s;
    for(int i=0;i<in.size();i++)s+='0'+in[i];
    return s;
}
string rever(string in){
    string s(in.size(),'_');
    for(int i=0;i<in.size();i++)s[in[i]-'1']='1'+i;
    return s;
}
void solve(){
    int n,m,ans=0;cin>>n>>m;
    vector<string> a(n),b(n);
    for(int i=0;i<n;i++){
        VI tt(m);
        for(int j=0;j<m;j++)cin>>tt[j];
        a[i]=b[i]=tostr(tt);
        b[i]=rever(b[i]);
    }
    sort(all(a));
    for(int i=0;i<n;i++){
        cout<<a[i]<<' '<<b[i]<<endl;
    }
    for(int i=0;i<n;i++){
        int k,j=lower_bound(all(a),b[i])-a.begin();
        //for(k=0;k<m&&a[j][k]==b[i][k];k++);
        cout<<j<<':'<<k<<' ';
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