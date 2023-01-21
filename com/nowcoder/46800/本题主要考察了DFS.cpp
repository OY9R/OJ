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
    string s;
    int a=0,b=0;
    for(int i=0;i<n*n-1;i++){
        cin>>s;
        for(int j=0;j<4;j++){
            if(j*2){
                if(s[j]=='2')b--;
                if(s[j]=='1')b++;
            }else{
                if(s[j]=='2')a--;
                if(s[j]=='1')a++;
            }
        }
    }
    cout<<10+a+b<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}