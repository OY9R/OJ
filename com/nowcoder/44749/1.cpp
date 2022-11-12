#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100100;
const int mod=1000000007;
ll CatalanNum[N];
ll inv[N];
inline void Catalan_Mod(int N){
    inv[1] = 1;
    for(int i=2; i<=N+1; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    CatalanNum[0] = CatalanNum[1] = 1;
    for(int i=2; i<=N; i++)
        CatalanNum[i] = CatalanNum[i-1] * (4 * i - 2) %mod * inv[i+1] %mod;
}
int main() {
    int t;cin>>t;
    while (t--)
    {
    int n;
    cin>>n;
    Catalan_Mod(n);
    cout<<CatalanNum[n]*n%mod<<' '<<CatalanNum[n]%mod;
    return 0;
    }
}