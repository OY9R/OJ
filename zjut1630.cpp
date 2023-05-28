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
void solve(string s){
    int n=s.size();
    if(n<5){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<=5;i++){
        // cout<<s.substr(0,i)+s.substr(n-5+i)<<' ';
        if(s.substr(0,i)+s.substr(n-5+i)=="QunHe"){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(string s;cin>>s;)solve(s);
    return 0;
}