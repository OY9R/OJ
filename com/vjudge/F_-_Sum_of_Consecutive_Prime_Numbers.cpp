#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
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
const int N=114515,INF=0x3f3f3f3f,mod=1e9+7;
int primes[N],cnt;
bool st[N];
void getPrimes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i])primes[cnt++]=i;
        for(int j=0;primes[j]<n/i;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}
void solve(){
    int n,res=0;cin>>n;
    if(!n)exit(0);
    for(int i=0;i<114514&&n>=primes[i];i++){
        int j=i,sum=primes[i];
        while(sum<n&&j<114514)sum+=primes[++j];
        res+=sum==n;
    }
    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    getPrimes(114514);
    while(true)solve();
    return 0;
}