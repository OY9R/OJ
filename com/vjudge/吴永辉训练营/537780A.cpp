#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
const int N=1024;
bool p[10001];
void initp(int n){
    for(int i=3;i<=n;i+=2)p[i]=true;
    for(int i=3;i*i<=n;i+=2)
        for(int j=i+i+i;j<=n;j+=i+i)
            p[j]=false;
}
int a,b;
queue<PII> q;
bool st[10001];
void solve(){
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    memset(st,0,sizeof st);
    q=queue<PII>();
    st[a]=true;
    q.push(make_pair(a,0));
    while(q.size()){
        PII t=q.front();
        q.pop();
        for(int i=1;i<=1000;i*=10){
            int tt=t.first/i%10*i;
            for(int j=0;j<10;j++){
                if(i==1000&&j==0)continue;
                int ttt=t.first-tt+j*i;
                if(t.first==ttt)continue;
                if(ttt==b){
                    cout<<t.second+1<<endl;
                    return;
                }
                if(!st[ttt]&&p[ttt]){
                    //cout<<ttt<<' ';
                    st[ttt]=true;
                    q.push(make_pair(ttt,t.second+1));
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    initp(10000);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}