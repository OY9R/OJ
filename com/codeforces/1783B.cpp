#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
int g[55][55];
int check(int n){
    set<int> s;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i>0)s.insert(abs(g[i][j]-g[i-1][j]));
            if(j>0)s.insert(abs(g[i][j]-g[i][j-1]));
        }
    return s.size();
}
void solve(){
    int n;cin>>n;
    for(int i=0,j=1;i<n*n;i+=2,j++)
        g[i/n][(i/n%2)?n-i%n-1:i%n]=j;
    for(int i=1,j=n*n;i<n*n;i+=2,j--)
        g[i/n][(i/n%2)?n-i%n-1:i%n]=j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<g[i][j]<<' ';
        cout<<endl;
    }
    //cout<<check(n)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}