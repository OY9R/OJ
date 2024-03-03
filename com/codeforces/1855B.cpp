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
    	ll n;cin>>n;
        int ans=1;
        for(ll i=1;i*i<=n;i+=ans*(ans+1)){
            if(n%i==0){
                int m=1;
                for(int j=1;i-j>0&&n%(i-j)==0;j++)m++;
                for(i++;n%i==0;i++)m++;
                ans=max(ans,m);
            }
        }
        cout<<ans<<endl;
    }
    int main(){
    	ios::sync_with_stdio(false);
    	cin.tie(0);cout.tie(0);
    	int n;cin>>n;
    	while(n--)solve();
    	return 0;
    }