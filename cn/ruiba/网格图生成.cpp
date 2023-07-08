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
void solve1(){
    int n,m;cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    srand(time(0));
    for(int i=0;i<n;i++){
        cout<<rand()%50+50<<endl;
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        int u=rand()%n+1,v=rand()%n+1;
        while(u==v)u=rand()%n+1,v=rand()%n+1;
        int w=rand()%100+1;
        cout<<u<<" "<<v<<" "<<w<<endl;
    }
}
void solve(){
    int x,y;cin>>x>>y;
    cout<<x*y<<" "<<x*(y-1)+(x-1)*y<<endl;
    //srand(time(0));
    vector<int> m(x*y);
    for(int i=0;i<x*y;i++){
        // cout<<i+1<<"-"<<(m[i]=rand()%50+50)<<endl;
        cout<<(m[i]=rand()%50+50)<<endl;
    }
    for(int i=1;i<=x*(y-1);i++){
        int u=i,v=i+x;
        int w=rand()%100+1;
        // cout<<u<<"-"<<m[u-1]<<" "<<v<<"-"<<m[v-1]<<" "<<w<<endl;
        cout<<u<<" "<<v<<" "<<w<<endl;
    }
    for(int i=1;i<=x*y;i++){
        if(i%x!=0){
            int u=i,v=i+1;
            int w=rand()%100+1;
            // cout<<u<<"-"<<m[u-1]<<" "<<v<<"-"<<m[v-1]<<" "<<w<<endl;
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}