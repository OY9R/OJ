#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
int n,m,i,t;
string s;
void dfs(int a,int b){
    int t=0;
    while(s[i]=='d')
        i++,t++,dfs(a+1,b+t);
    i++,n=max(n,a),m=max(m,b);
}
void solve(){
    n=0,m=0,i=0;
    dfs(0,0);
    cout<<"Tree "<<++t<<": "<<n<<" => "<<m<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin>>s&&s!="#")solve();
    return 0;
}