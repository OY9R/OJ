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
const int INF=0x3f3f3f3f,mod=1e9+7,N=10000000;
ll prime[N];
bool is_prime[N];
int cnt;
void get_prime(int n){
    memset(is_prime,1,sizeof(is_prime));
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<=n;i++){
        if(is_prime[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
            is_prime[i*prime[j]]=0;
            if(i%prime[j]==0)break;
        }
    }
}
void test(){
    VL p;
    get_prime(10000000);
    for(int i=0;i<10;i++)cout<<prime[i]<<' ';
    cout<<endl;
    cout<<cnt<<' '<<prime[cnt-1]<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int n;cin>>n;
	// while(n--)solve();
    test();
	return 0;
}