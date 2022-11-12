#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = INT_MAX>>5;
int primes[N],cnt;
bool st[N];
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i])primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}
int get_min_primes(ll x){
    for(int i=0;i<N;i++){
        if(x%primes[i]==0)
            return primes[i];
    }
    return 0;
}
int main(){
    get_primes(N);
    ll s,e,k;
    cin>>s>>e>>k;
    vector<int> a;
    for(ll i=s;i<=e;i++){
        a.push_back(get_min_primes(i));
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<k;i++){
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}